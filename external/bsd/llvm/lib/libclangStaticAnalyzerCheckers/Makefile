#	$NetBSD: Makefile,v 1.17 2012/10/28 17:07:47 joerg Exp $

LIB=	clangStaticAnalyzerCheckers

.include <bsd.init.mk>

.PATH: ${CLANG_SRCDIR}/lib/StaticAnalyzer/Checkers

SRCS+=	AnalyzerStatsChecker.cpp \
	ArrayBoundChecker.cpp \
	ArrayBoundCheckerV2.cpp \
	AttrNonNullChecker.cpp \
	BasicObjCFoundationChecks.cpp \
	BoolAssignmentChecker.cpp \
	BuiltinFunctionChecker.cpp \
	ClangCheckers.cpp \
	CStringChecker.cpp \
	CStringSyntaxChecker.cpp \
	CallAndMessageChecker.cpp \
	CastSizeChecker.cpp \
	CastToStructChecker.cpp \
	CheckObjCDealloc.cpp \
	CheckObjCInstMethSignature.cpp \
	CheckSecuritySyntaxOnly.cpp \
	CheckSizeofPointer.cpp \
	CheckerDocumentation.cpp \
	ChrootChecker.cpp \
	CommonBugCategories.cpp \
	DeadStoresChecker.cpp \
	DebugCheckers.cpp \
	DereferenceChecker.cpp \
	DirectIvarAssignment.cpp \
	DivZeroChecker.cpp \
	DynamicTypePropagation.cpp \
	ExprInspectionChecker.cpp \
	FixedAddressChecker.cpp \
	GenericTaintChecker.cpp \
	IdempotentOperationChecker.cpp \
	IvarInvalidationChecker.cpp \
	LLVMConventionsChecker.cpp \
	MacOSKeychainAPIChecker.cpp \
	MacOSXAPIChecker.cpp \
	MallocChecker.cpp \
	MallocOverflowSecurityChecker.cpp \
	MallocSizeofChecker.cpp \
	NSAutoreleasePoolChecker.cpp \
	NSErrorChecker.cpp \
	NoReturnFunctionChecker.cpp \
	ObjCAtSyncChecker.cpp \
	ObjCContainersASTChecker.cpp \
	ObjCContainersChecker.cpp \
	ObjCSelfInitChecker.cpp \
	ObjCUnusedIVarsChecker.cpp \
	PointerArithChecker.cpp \
	PointerSubChecker.cpp \
	PthreadLockChecker.cpp \
	RetainCountChecker.cpp \
	ReturnPointerRangeChecker.cpp \
	ReturnUndefChecker.cpp \
	StackAddrEscapeChecker.cpp \
	StreamChecker.cpp \
	TaintTesterChecker.cpp \
	TraversalChecker.cpp \
	UndefBranchChecker.cpp \
	UndefCapturedBlockVarChecker.cpp \
	UndefResultChecker.cpp \
	UndefinedArraySubscriptChecker.cpp \
	UndefinedAssignmentChecker.cpp \
	UnixAPIChecker.cpp \
	UnreachableCodeChecker.cpp \
	VLASizeChecker.cpp \
	VirtualCallChecker.cpp

CLANG_TABLEGEN_SRC=		Checkers.td
CLANG_TABLEGEN_INCLUDES=	-I${CLANG_SRCDIR}/include
CLANG_TABLEGEN_OUTPUT=	Checkers.inc|-gen-clang-sa-checkers

.include "${.PARSEDIR}/../../tablegen.mk"

.if defined(HOSTLIB)
.include <bsd.hostlib.mk>
.else
.include <bsd.lib.mk>
.endif
