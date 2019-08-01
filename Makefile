# antiold metamod plugin Makefile for linux and win32 (mingw)

LFLAGS = -shared -lm
ARCH = $(shell uname -m)
AO_COMMIT = $(firstword $(shell git rev-parse --short=6 HEAD) unknown)
CFLAGS =  -DVVERSION=\"$(AO_COMMIT)\" -fexpensive-optimizations -Wall -fno-exceptions \
	  -funsafe-loop-optimizations -fomit-frame-pointer -funsafe-math-optimizations \
	  -Dstricmp=strcasecmp -D_strnicmp=strncasecmp -Dstrnicmp=strncasecmp -Dstrcmpi=strcasecmp

# force i686 postfix on x86_64 architecture
ifeq ($(ARCH), x86_64)
	DLLNAME = antiold_mm_i686.so
else
	DLLNAME = antiold_mm_$(ARCH).so
endif

# debug
ifeq ($(DEBUG), 1)
	CFLAGS += -DDEBUG -g -ggdb
else
	CFLAGS += -O1
endif

# architecture depended flags
ifeq ($(ARCH), x86_64)
	LFLAGS += -m32
	CFLAGS += -march=i686 -m32
endif

INCLUDEDIRS = -Isrc/. \
	      -Isrc/include/metamod \
	      -Isrc/include/hlsdk-xash3d/engine \
	      -Isrc/include/hlsdk-xash3d/common \
	      -Isrc/include/hlsdk-xash3d/dlls

OBJ =	src/callbacks.o		\
        src/commands.o		\
        src/dllapi.o		\
        src/engine_api.o	\
        src/h_export.o		\
        src/meta_api.o		\
        src/utils.o

DOCC = $(CXX) $(CFLAGS) $(INCLUDEDIRS) -o $@ -c $<
DOO = $(CXX) -o $@ $(OBJ) $(LFLAGS)

$(DLLNAME) : $(OBJ)
	$(DOO)

clean:
	rm -f $(OBJ) $(DLLNAME)

./%.o: ./%.cpp
	$(DOCC)
