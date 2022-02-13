TARGET = cmd_parser
CC     = gcc

# -g: Produce debugging information in the operating system’s native format. 
#     GDB can work with this debugging information
# -O2:	GCC performs nearly all supported optimizations that do
#	not involve a space-speed tradeof
# -pipe: Use pipes rather than temporary files for communication between
#	 the various stages of compilation.
# -Wall: This enables all the warnings about constructions that some users 
#	 consider questionable, and that are easy to avoid 
#	 (or modify to prevent the warning), even in conjunction with macros.
# -Wextra: This enables some extra warning flags that are not enabled by ‘-Wall’.

CFLAGS = -g -O2 -pipe -Wall -Wextra

OBJECTS = arg_ap.o arg_parser.o behavior_keys.o global.o main.o

all: main.o arg_ap.o arg_parser.o behavior_keys.o global.o
	$(CC) main.o arg_ap.o arg_parser.o behavior_keys.o global.o -o $(TARGET)

clean:
	rm -rf *.o $(TARGET)
	
distclean: clean


arg_ap.o: arg_ap.c
	$(CC) -c arg_ap.c
	
arg_parser.o: arg_parser.c
	$(CC) -c arg_parser.c

behavior_keys.o: behavior_keys.c
	$(CC) -c behavior_keys.c

global.o: global.c
	$(CC) -c global.c

main.o: main.c
	$(CC) -c main.c
