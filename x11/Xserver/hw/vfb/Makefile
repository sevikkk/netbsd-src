#	$NetBSD: Makefile,v 1.6 2004/02/07 06:52:05 lukem Exp $

.include "../../Makefile.serverlib"

LIB=		vfb
.PATH:		${X11SRCDIR.xc}/programs/Xserver/hw/vfb
.PATH:		${X11SRCDIR.xc}/programs/Xserver/Xext
.PATH:		${X11SRCDIR.xc}/programs/Xserver/Xi
.PATH:		${X11SRCDIR.xc}/programs/Xserver/mi

SRCS=		InitInput.c InitOutput.c dpmsstubs.c miinitext.c stubs.c

CPPFLAGS+=	-I${DESTDIR}${X11INCDIR}/X11 \
		-I${X11SRCDIR.xc}/include/fonts \
		-I${X11SRCDIR.xc}/programs/Xserver/fb \
		-I${X11SRCDIR.xc}/programs/Xserver/mfb \
		-I${X11SRCDIR.xc}/programs/Xserver/mi \
		-I${X11SRCDIR.xc}/programs/Xserver/include \
		-I${XSERVERINCDIR} \
		-I${X11SRCDIR.xc}/programs/Xserver/os \
		-I${DESTDIR}${X11INCDIR}/X11/extensions \
		-I${X11SRCDIR.xc}/programs/Xserver/render

CPPFLAGS+=	${X11FLAGS.OS_DEFINES} \
		-DHAS_SHM -DHAS_MMAP -UXFree86LOADER

.include "../../Makefile.common"

.if ${XSERVER_XFREE86} == "no"
CPPFLAGS+=	-UDDXTIME
.endif

CPPFLAGS.InitInput.c=	${X11FLAGS.EXTENSION}
CPPFLAGS.miinitext.c=	${X11FLAGS.EXTENSION} \
			-DNO_HW_ONLY_EXTS -DNO_MODULE_EXTS -UXFree86LOADER
CPPFLAGS.dpmsstubs.c=	${X11FLAGS.EXTENSION}

.include <bsd.x11.mk>
.include <bsd.lib.mk>
