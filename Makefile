# ------------------------------------------------------
# File    : src/cross/Makefile
#
# Autor   : Jens Kallup <kallup.jens@web.de> - paule32
# License : (c) kallup.net - non-profit - 2021
# ----------------------------------------------------------------
# This Makefile was hand-coded. So if you found bugs, please
# let it me know, and write a bug report to: <kallup.jens@web.de>
# This project and all it's content are tested under:
# - Microsoft Windows 10 Pro 64-Bit Edition.
# -
# I don't give any gurantees of correct, and stable using!
# YOU USE IT, AT YOUR OWN RISK !
# ----------------------------------------------------------------

# -----------------------------------------------------
APP_TYPE    = console
FPC_VERSION = 3.2.0
OS_PLATFORM = WINDOWS

# --------------------------------------------------
# this section is user/developer speciefic.
# you have to set on your own ...
# --------------------------------------------------
CC        = gcc    # i used MinGW-64 8.6.0
FPC       = fpc    # tests with 3.2.0
GDB       = gdb    # command line

# ---------------------------------------------------------
# the command's below should be come with the MinGW Utils.
# ---------------------------------------------------------
WINDRES   = windres
RM        = rm -rf
MKDIR     = mkdir -p
COPY      = cp
ECHO      = echo
SED       = sed
STRIP     = strip

# ----------------------------------------
# gnu c/c++ speciefied compiler flags.
# default: win64
# ----------------------------------------
CFLAGS    = -m64 -I. -O2 -DAPP_TYPE=$(APP_TYPE) -D$(OS_PLATFORM)
FPC_FLAGS = -n -s -Ur -Xe -WN -O2
GDB_FLAG  = -ggdb

CXX       = g++
CXX_LIBS  = -lstdc++ -lm
CXX_FLAGS = \
	${CFLAGS} -std=c++17 -c -D_GLIBCXX_USE_CXX11_ABI=0 \
	${INCLUDES_PATH} -fPIC \
	-Wno-write-strings \
	-Wno-deprecated-declarations

# -----------------------
# temporary settings ...
# -----------------------
OUT_DIR = build
OBJ_DIR = ${OUT_DIR}/.obj
RCC_DIR = ${OUT_DIR}/.res

# ---------------------------
# the source directories ...
# ---------------------------
SRC_DIR = src
CXX_SRC = ${SRC_DIR}/gcc
INC_DIR = ${SRC_DIR}/inc
RES_SRC = ${SRC_DIR}/assets/res

CXX_OBJ = ${OBJ_DIR}
RES_OBJ = ${RCC_DIR}

INCLUDES_PATH = \
	-I ${SRC_DIR}/../boost \
	-I ${SRC_DIR}/inc      \
	-I .

CXX_SOURCE_FILES = \
	${CXX_SRC}/main.cc \
	${CXX_SRC}/vars.cc

OBJ_SOURCE_FILES = \
	${CXX_OBJ}/main.cc.o\
	${CXX_OBJ}/vars.cc.o\
	\
	${RES_OBJ}/version.rc.o

INC_SOURCE_FILES = \
	${INC_DIR}/error.hpp\
	${INC_DIR}/string.hpp\
	${INC_DIR}/windows.hpp\
	${INC_DIR}/resource.h

RES_SOURCE_FILES = \
	${RES_SRC}/main.rc \
	${RES_SRC}/version.rc

# pre-compiled headers:
PCH_FILES = \
	${INC_DIR}/common.pch.hpp\
	${INC_DIR}/windows.pch.hpp
# ----------
PCH_FILES_GCH = \
	${INC_DIR}/common.pch.hpp.gch\
	${INC_DIR}/windows.pch.hpp.gch


# windows library files ...
LIBS = \
	-l comctl32		\
	-l gdi32 		\
	-l kernel32		\
	-l user32

all: pre_tasks github pre_header main

main: ${OUT_DIR}/libzwip.dll

pre_header: ${PCH_FILES_GCH}

${INC_DIR}/%.pch.hpp.gch: ${INC_DIR}/%.pch.hpp
	${CXX} ${CXX_FLAGS} -x c++-header -c $^ -o $@

${OUT_DIR}/libzwip.dll: ${OBJ_SOURCE_FILES} ${RCC_FILES}
	${CXX} -fPIC -shared -o ${OUT_DIR}/libzwip.dll  $^ ${LIBS}
	${STRIP}  ${OUT_DIR}/libzwip.dll

${CXX_OBJ}/%.cc.o: ${CXX_SRC}/%.cc
	${CXX} ${CXX_FLAGS} -c $^ -o $@
	
${RCC_DIR}/%.rc.o: ${RES_SRC}/%.rc
	${WINDRES} ${INCLUDES_PATH} $^ -O coff $@

# -------------------------------------------
# before the compiler run, save the changed
# data to the github/paule32 account:
# -------------------------------------------
github:
	rm -rf src/inc/*.gch
	git config --global user.email "kallup.jens@web.de"
	git config --global user.name  "paule32"
	git add build\*.*
	git add src\*.*
	git commit -a -m "update"
	git push

# -------------------------------------------
# this section, create temporary folder's ...
# -------------------------------------------
PRE_FOLDERS = \
	${OBJ_DIR}\
	${RCC_DIR}

pre_tasks:
	$(foreach folder,$(PRE_FOLDERS),$(MKDIR) $(folder) && ) true

# -------------------------------------------
# this target, remove all temporary files ...
# -------------------------------------------
clean:
	@$(ECHO) delete source folder crap ...
	$(foreach folder,$(PRE_FOLDERS),$(RM) $(folder) && ) true
