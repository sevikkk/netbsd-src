#	$NetBSD: Makefile,v 1.9 2011/07/25 18:23:14 mrg Exp $

.include <bsd.own.mk>

SUBDIR=	config internal

.PATH:	${X11SRCDIR.freetype}/include/freetype

INCSDIR=${X11INCDIR}/freetype2/freetype

INCS=	freetype.h ftadvanc.h ftbbox.h ftbdf.h ftbitmap.h ftbzip2.h ftcache.h \
	ftchapters.h ftcid.h fterrdef.h fterrors.h ftgasp.h ftglyph.h \
	ftgxval.h ftgzip.h ftimage.h ftincrem.h ftlcdfil.h ftlist.h \
	ftlzw.h ftmac.h ftmm.h ftmodapi.h ftmoderr.h ftotval.h ftoutln.h \
	ftpfr.h ftrender.h ftsizes.h ftsnames.h ftstroke.h ftsynth.h \
	ftsystem.h fttrigon.h fttypes.h ftwinfnt.h ftxf86.h \
	t1tables.h ttnameid.h tttables.h tttags.h ttunpat.h

SCRIPTS=	freetype-config

CLEANFILES+=	${SCRIPTS}

# XXX hijack config-subst from Xft
CONFIG_SUBST=	${TOOL_SED} -e 's%@prefix@%${X11ROOTDIR}%' \
		-e 's%@exec_prefix@%${X11BINDIR}%' \
		-e 's%@libdir@%${X11USRLIBDIR}%g' \
		-e 's%@includedir@%${X11INCDIR}%' \
		-e 's%@ft_version@%9.17.3%' \
		-e 's%@FT2_EXTRA_LIBS@%%' \
		-e 's%@build_libtool_libs@%yes%' \
		-e 's%@hardcode_libdir_flag_spec@%-Wl,-rpath,${X11USRLIBDIR}%' \
		-e 's%@LIBZ@%-lz%' \
		-e 's%@LIBBZ2@%-lbz2%'

.PATH: ${X11SRCDIR.freetype}/builds/unix
freetype-config: freetype-config.in
	${_MKTARGET_CREATE}
	${CONFIG_SUBST} < ${.ALLSRC} > ${.TARGET}

.include <bsd.x11.mk>
.include <bsd.prog.mk>
.include <bsd.subdir.mk>
