# $NetBSD: Makefile,v 1.43 2012/09/27 00:38:57 joerg Exp $

.include "Makefile.inc"
.include <bsd.sys.mk>
.include <bsd.own.mk>

SUBDIR+=	tls_dso .WAIT

TESTS_SUBDIRS+=	db gen hash inet locale net regex rpc setjmp stdlib
TESTS_SUBDIRS+=	stdio string sys termios time tls ttyio

.if ${HAS_SSP} == "yes"
TESTS_SUBDIRS+=	ssp
.endif

TESTSDIR=	${TESTSBASE}/lib/libc

TESTS_C+=	t_convfp
TESTS_C+=	t_gdtoa
TESTS_C+=	t_cdb

.include <bsd.test.mk>
