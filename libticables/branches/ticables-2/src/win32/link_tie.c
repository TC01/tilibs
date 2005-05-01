/* Hey EMACS -*- win32-c -*- */
/* $Id$ */

/*  libticables - Ti Link Cable library, a part of the TiLP project
 *  Copyright (C) 1999-2005  Romain Lievin
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/* "TiEmulator" virtual link cable unit */

/* 
 *  This unit use two FIFOs between 2 program which use this lib.
 *  Convention used: 0 is an emulator and 1 is a linking program.
 *  One pipe is used for transferring information from 0 to 1 and the other
 *  pipe is used for transferring from 1 to 0.
 */

#include <stdio.h>

#include "../ticables.h"
#include "../logging.h"
#include "../error.h"
#include "../gettext.h"
#include "detect.h"

#define BUFSIZE 256

static const char name[4][256] = 
{
  "GtkTiEmu Virtual Link 0", "GtkTiEmu Virtual Link 1",
  "GtkTiEmu Virtual Link 1", "GtkTiEmu Virtual Link 0"
};

#ifdef __GNUC__						// Kevin Kofler
static int ref_cnt __attribute__ ((section(".shared"), shared)) = 0;
#else
#pragma comment(linker, "/SECTION:.shared,RWS")
#pragma data_seg(".shared")			// Share these variables between different instances
static int volatile	ref_cnt = 0;	// Counter of library instances
#pragma data_seg()
#endif

typedef struct 
{
  BYTE buf[BUFSIZE];
  int start;
  int end;
} LinkBuffer;

static HANDLE hSendBuf, hRecvBuf;
static LinkBuffer *pSendBuf, *pRecvBuf;

static int tie_prepare(TiHandle *h)
{
	h->address = 0;
	h->device = strdup("");

	return 0;
}

static int tie_open(TiHandle *h)
{
	int p;

  /* Check if valid argument */
  if ((h->address < 1) || (h->address > 2)) 
  {
		ticables_info(_("invalid h->address parameter passed to libticables."));
		h->address = 2;
  } 
  else 
  {
		p = h->address - 1;
		ref_cnt++;
  }

  /* Create a FileMapping objects */
  hSendBuf = CreateFileMapping((HANDLE) (-1), NULL, PAGE_READWRITE, 0, sizeof(LinkBuffer), (LPCTSTR) name[2 * p + 0]);
  if (hSendBuf == NULL) 
		return ERR_OPENFILEMAPPING;

  hRecvBuf = CreateFileMapping((HANDLE) (-1), NULL, PAGE_READWRITE, 0, sizeof(LinkBuffer), (LPCTSTR) name[2 * p + 1]);
  if (hRecvBuf == NULL) 
		return ERR_OPENFILEMAPPING;

  /* Map them */
  pSendBuf = (LinkBuffer *) MapViewOfFile(hSendBuf, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(LinkBuffer));
  if (pSendBuf == NULL) 
		return ERR_MAPVIEWOFFILE;

  pRecvBuf = (LinkBuffer *) MapViewOfFile(hRecvBuf, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(LinkBuffer));
  if (pRecvBuf == NULL) 
		return ERR_MAPVIEWOFFILE;

	pSendBuf->start = pSendBuf->end = 0;
  pRecvBuf->start = pRecvBuf->end = 0;

	return 0;
}

static int tie_close(TiHandle *h)
{
  /* Close the shared buffer */
  if (hSendBuf) 
    UnmapViewOfFile(pSendBuf);

  if (hRecvBuf) 
    UnmapViewOfFile(pRecvBuf);

  return 0;
}

static int tie_reset(TiHandle *h)
{
	pSendBuf->start = pSendBuf->end = 0;
	pRecvBuf->start = pRecvBuf->end = 0;

	return 0;
}

static int tie_put(TiHandle *h, uint8_t *data, uint16_t len)
{
	int i;
	tiTIME clk;

	for(i = 0; i < len; i++)
	{
		TO_START(clk);
		do 
		{
		  if (TO_ELAPSED(clk, h->timeout))
			return ERR_WRITE_TIMEOUT;
		}
		while (((pSendBuf->end + 1) & (BUFSIZE-1)) == pSendBuf->start);

		pSendBuf->buf[pSendBuf->end] = data[i];
		pSendBuf->end = (pSendBuf->end + 1) & (BUFSIZE-1);
	}
	
	return 0;
}

static int tie_get(TiHandle *h, uint8_t *data, uint16_t len)
{
	int i;
	tiTIME clk;

	for(i = 0; i < len; i++)
	{
		TO_START(clk);
		do 
		{
			if (TO_ELAPSED(clk, h->timeout))
				return ERR_READ_TIMEOUT;
		}
		while (pRecvBuf->start == pRecvBuf->end);

		/* And retrieve the data from the circular buffer */
		data[i] = pRecvBuf->buf[pRecvBuf->start];
		pRecvBuf->start = (pRecvBuf->start + 1) & (BUFSIZE-1);
	}

	return 0;
}

static int tie_probe(TiHandle *h)
{
	return 0;
}

static int tie_check(TiHandle *h, int *status)
{
	if (pRecvBuf->start == pRecvBuf->end)
		*status = STATUS_NONE;
	else
		*status = STATUS_RX;

	return 0;
}

static int tie_set_red_wire(TiHandle *h, int b)
{
	return 0;
}

static int tie_set_white_wire(TiHandle *h, int b)
{
	return 0;
}

static int tie_get_red_wire(TiHandle *h)
{
	return 1;
}

static int tie_get_white_wire(TiHandle *h)
{
	return 1;
}

const TiCable cable_tie = 
{
	CABLE_TIE,
	"TIE",
	N_("TiEmu"),
	N_("Virtual link for TiEmu"),

	&tie_prepare, &tie_probe,
	&tie_open, &tie_close, &tie_reset,
	&tie_put, &tie_get, &tie_check,
	&tie_set_red_wire, &tie_set_white_wire,
	&tie_get_red_wire, &tie_get_white_wire,
};