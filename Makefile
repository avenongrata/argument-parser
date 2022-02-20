
TARGET = cmd_parser

#------------------------------------------------------------------------------

# use std path
SDK_DIR  = 
SDK_BIN  = 
SDK_PREF =

DISTDIR = .
INCPATH = -I.
LIBS    = 
DEFINES = 

#------------------------------------------------------------------------------

# -g: Produce debugging information in the operating system’s native format. 
#     GDB can work with this debugging information
# -O2:	GCC performs nearly all supported optimizations that do
#	not involve a space-speed tradeof
# -pipe: Use pipes rather than temporary files for communication between
#	 the various stages of compilation.
# -Wall: This enables all the warnings about constructions that some users 
#	 consider questionable, and that are easy to avoid 
#	 (or modify to prevent the warning), even in conjunction with macros.
# -Wextra: This enables some extra warning flags that are not enabled 
#	   by ‘-Wall’.
# -fPIC: Generate position-independent code (PIC) suitable for use 
#	 in a shared library, if supported for the target machine. 

CFLAGS  = -g -O2 -pipe -Wall -Wextra $(DEFINES)

OBJECTS = arg_ap.o arg_parser.o behavior_keys.o global.o main.o

LFLAGS  =

#------------------------------------------------------------------------------

# Build for ARM instad of x86/x86_64

ifeq ($(arch), arm)
	SDK_DIR  = /opt/radiomodule-sdk
	SDK_BIN  = $(SDK_DIR)/bin
	SDK_PREF = $(SDK_BIN)/arm-linux-
endif

#------------------------------------------------------------------------------

# Create dynamic library instead of ELF

ifeq ($(lib), 1)
	TARGET    = libparser.so
	DISTDIR   = ./lib
	OBJECTS = arg_ap.o arg_parser.o behavior_keys.o global.o

	INCPATH   = -I.
	LIBS      = -L./lib
	CFLAGS    = -g -pipe -Wall -Wextra -fPIC $(DEFINES)
	LFLAGS    = -shared -Wl,-soname,$(TARGET)
endif

#------------------------------------------------------------------------------

TAR_FILE = $(DISTDIR)/$(TARGET)

#------------------------------------------------------------------------------

CC = $(SDK_PREF)gcc $(LFLAGS)

#------------------------------------------------------------------------------

all: distclean $(OBJECTS)
	test -d $(DISTDIR) || mkdir -p $(DISTDIR);
	$(CC) $(OBJECTS) -o $(TAR_FILE)

clean:
	rm -rf *.o $(TAR_FILE)

distclean: clean
	rm -f $(TAR_FILE)
	rm -rf ./lib

arg_ap.o: arg_ap.c
	$(CC) $(CFLAGS) -c arg_ap.c

arg_parser.o: arg_parser.c
	$(CC) $(CFLAGS) -c arg_parser.c

behavior_keys.o: behavior_keys.c
	$(CC) $(CFLAGS) -c behavior_keys.c

global.o: global.c
	$(CC) $(CFLAGS) -c global.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c
