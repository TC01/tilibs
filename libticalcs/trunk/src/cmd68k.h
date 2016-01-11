/* Hey EMACS -*- linux-c -*- */
/* $Id$ */

/*  libticalcs - Ti Calculator library, a part of the TiLP project
 *  Copyright (C) 1999-2005  Romain Li�vin
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
 *  along with this program; if not, write to the Free Software Foundation,
 *  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

// /!\ NOTE: for this file, backwards compatibility will not necessarily be maintained as strongly as it is for ticalcs.h !

#ifndef __TICALCS_CMD68K__
#define __TICALCS_CMD68K__

#ifdef __cplusplus
extern "C" {
#endif

/* TI-89 family, send functions */
TIEXPORT3 int TICALL ti89_send_VAR(CalcHandle *handle, uint32_t varsize, uint8_t vartype, const char *varname);
TIEXPORT3 int TICALL ti89_send_CTS(CalcHandle *handle);
TIEXPORT3 int TICALL ti89_send_XDP(CalcHandle *handle, uint32_t length, const uint8_t * data);
TIEXPORT3 int TICALL ti89_send_SKP(CalcHandle *handle, uint8_t rej_code);
TIEXPORT3 int TICALL ti89_send_ACK(CalcHandle *handle);
TIEXPORT3 int TICALL ti89_send_ERR(CalcHandle *handle);
TIEXPORT3 int TICALL ti89_send_RDY(CalcHandle *handle);
TIEXPORT3 int TICALL ti89_send_SCR(CalcHandle *handle);
TIEXPORT3 int TICALL ti89_send_CNT(CalcHandle *handle);
TIEXPORT3 int TICALL ti89_send_KEY(CalcHandle *handle, uint16_t scancode);
TIEXPORT3 int TICALL ti89_send_EOT(CalcHandle *handle);
TIEXPORT3 int TICALL ti89_send_REQ(CalcHandle *handle, uint32_t varsize, uint8_t vartype, const char *varname);
TIEXPORT3 int TICALL ti89_send_RTS(CalcHandle *handle, uint32_t varsize, uint8_t vartype, const char *varname);
TIEXPORT3 int TICALL ti89_send_RTS2(CalcHandle *handle, uint32_t varsize, uint8_t vartype, uint8_t hw_id);
TIEXPORT3 int TICALL ti89_send_VER(CalcHandle *handle);
TIEXPORT3 int TICALL ti89_send_DEL(CalcHandle *handle, uint32_t varsize, uint8_t vartype, const char *varname);

/* TI-89 family, receive functions */
TIEXPORT3 int TICALL ti89_recv_VAR(CalcHandle *handle, uint32_t * varsize, uint8_t * vartype, char *varname);
TIEXPORT3 int TICALL ti89_recv_CTS(CalcHandle *handle);
TIEXPORT3 int TICALL ti89_recv_SKP(CalcHandle *handle, uint8_t * rej_code);
TIEXPORT3 int TICALL ti89_recv_XDP(CalcHandle *handle, uint16_t * length, uint8_t * data);
TIEXPORT3 int TICALL ti89_recv_ACK(CalcHandle *handle, uint16_t * status);
TIEXPORT3 int TICALL ti89_recv_CNT(CalcHandle *handle);
TIEXPORT3 int TICALL ti89_recv_EOT(CalcHandle *handle);
TIEXPORT3 int TICALL ti89_recv_RTS(CalcHandle *handle, uint32_t * varsize, uint8_t * vartype, char *varname);


/* TI-92, send functions */
TIEXPORT3 int TICALL ti92_send_VAR(CalcHandle *handle, uint32_t varsize, uint8_t vartype, const char *varname);
TIEXPORT3 int TICALL ti92_send_CTS(CalcHandle *handle);
TIEXPORT3 int TICALL ti92_send_XDP(CalcHandle *handle, uint32_t length, const uint8_t * data);
TIEXPORT3 int TICALL ti92_send_SKP(CalcHandle *handle, uint8_t rej_code);
TIEXPORT3 int TICALL ti92_send_ACK(CalcHandle *handle);
TIEXPORT3 int TICALL ti92_send_ERR(CalcHandle *handle);
TIEXPORT3 int TICALL ti92_send_RDY(CalcHandle *handle);
TIEXPORT3 int TICALL ti92_send_SCR(CalcHandle *handle);
TIEXPORT3 int TICALL ti92_send_CNT(CalcHandle *handle);
TIEXPORT3 int TICALL ti92_send_KEY(CalcHandle *handle, uint16_t scancode);
TIEXPORT3 int TICALL ti92_send_EOT(CalcHandle *handle);
TIEXPORT3 int TICALL ti92_send_REQ(CalcHandle *handle, uint32_t varsize, uint8_t vartype, const char *varname);
TIEXPORT3 int TICALL ti92_send_RTS(CalcHandle *handle, uint32_t varsize, uint8_t vartype, const char *varname);

/* TI-92, receive functions */
TIEXPORT3 int TICALL ti92_recv_VAR(CalcHandle *handle, uint32_t * varsize, uint8_t * vartype, char *varname);
TIEXPORT3 int TICALL ti92_recv_CTS(CalcHandle *handle);
TIEXPORT3 int TICALL ti92_recv_SKP(CalcHandle *handle, uint8_t * rej_code);
TIEXPORT3 int TICALL ti92_recv_XDP(CalcHandle *handle, uint16_t * length, uint8_t * data);
TIEXPORT3 int TICALL ti92_recv_ACK(CalcHandle *handle, uint16_t * status);
TIEXPORT3 int TICALL ti92_recv_CNT(CalcHandle *handle);
TIEXPORT3 int TICALL ti92_recv_EOT(CalcHandle *handle);
TIEXPORT3 int TICALL ti92_recv_RTS(CalcHandle *handle, uint32_t * varsize, uint8_t * vartype, char *varname);

#ifdef __cplusplus
}
#endif

#endif
