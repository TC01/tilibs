/* Hey EMACS -*- linux-c -*- */
/* $Id: logging.h 665 2004-04-29 18:25:16Z tijl $ */

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

#ifndef __TICABLES_DATALOG__
#define __TICABLES_DATALOG__

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>

int start_logging();
int log_data(int data);
int stop_logging();

#ifdef ENABLE_LOGGING
# define START_LOGGING(); start_logging();
# define LOG_DATA(d);     log_data(d);
# define STOP_LOGGING();  stop_logging();
#else
# define START_LOGGING();
# define LOG_DATA(d);
# define STOP_LOGGING();
#endif

#endif