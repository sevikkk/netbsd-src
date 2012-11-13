#	$NetBSD: Makefile.walnut.inc,v 1.6 2012/02/01 21:46:02 matt Exp $

CFLAGS+=-mcpu=405
AFLAGS+=-mcpu=405
TEXTADDR?=	25000

SYSTEM_FIRST_OBJ=	esi_locore.o
SYSTEM_FIRST_SFILE=	${THISPPC}/esi/esi_locore.S
