/* Hey EMACS -*- linux-c -*- */
/* $Id$ */

/*  libtifiles - Ti File Format library, a part of the TiLP project
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

#ifndef __TIFILES_FILES9X_H__
#define __TIFILES_FILES9X_H__

#include "stdints.h"
#include "tifiles.h"

/* Constants */

#define DEVICE_TYPE_89  0x98
#define DEVICE_TYPE_92P 0x88

/* Structures */

typedef FileContent		Ti9xRegular;
typedef BackupContent	Ti9xBackup;
typedef FlashContent	Ti9xFlash;

/* Functions */

// allocating
Ti9xRegular* ti9x_content_create_regular(void);
Ti9xBackup*  ti9x_content_create_backup(void);
Ti9xFlash*   ti9x_content_create_flash(void);

// freeing
void ti9x_content_free_regular(Ti9xRegular *content);
void ti9x_content_free_backup(Ti9xBackup *content);
void ti9x_content_free_flash(Ti9xFlash *content);

// displaying
int ti9x_content_display_regular(Ti9xRegular *content);
int ti9x_content_display_backup(Ti9xBackup *content);
int ti9x_content_display_flash(Ti9xFlash *content);

// reading
int ti9x_file_read_regular(const char *filename, Ti9xRegular *content);
int ti9x_file_read_backup(const char *filename, Ti9xBackup *content);
int ti9x_file_read_flash(const char *filename, Ti9xFlash *content);

// writing
int ti9x_file_write_regular(const char *filename, Ti9xRegular *content, char **filename2);
int ti9x_file_write_backup(const char *filename, Ti9xBackup *content);
int ti9x_file_write_flash(const char *filename, Ti9xFlash *content);

// displaying
int ti9x_file_display(const char *filename);

#endif
