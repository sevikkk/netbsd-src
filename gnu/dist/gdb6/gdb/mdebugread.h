/* Read a symbol table in ECOFF format (Third-Eye).

   Copyright (C) 2004 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

#ifndef MDEBUGREAD_H
#define MDEBUGREAD_H

#include "coff/sym.h"		/* Needed for PDR below.  */
#include "coff/symconst.h"

/* Specific information about a procedure.  Architectures (ab)uses
   this to save memory.  */

struct mdebug_extra_func_info
{
  long numargs;		/* number of args to procedure (was iopt) */
  PDR pdr;			/* Procedure descriptor record */
};

/* Special symbol found in blocks associated with routines.  We can
   hang mdebug_extra_func_info's off of this.  */

#define MDEBUG_EFI_SYMBOL_NAME "__GDB_EFI_INFO__"

#endif /* MDEBUGREAD_H */
