/* Hey EMACS -*- linux-c -*- */
/* $Id$ */

/*  libticables2 - Ti File Format library, a part of the TiLP project
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
 *  along with this program; if not, write to the Free Software Foundation,
 *  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef __TICABLES_LOGGING__
#define __TICABLES_LOGGING__

#include <glib.h>

#define ticables_debug(format, ...) g_log("ticables", G_LOG_LEVEL_DEBUG, format, ##__VA_ARGS__)
#define ticables_info(format, ...) g_log("ticables", G_LOG_LEVEL_INFO, format, ##__VA_ARGS__)
#define ticables_warning(format, ...) g_log("ticables", G_LOG_LEVEL_WARNING, format, ##__VA_ARGS__)
#define ticables_critical(format, ...) g_log("ticables", G_LOG_LEVEL_CRITICAL, format, ##__VA_ARGS__)

#endif
