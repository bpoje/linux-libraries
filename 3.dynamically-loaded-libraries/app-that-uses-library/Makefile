# Notes:
# Symbol @ means don't print command
# The .ONESHELL: directive allows to write multiple line recipes to be executed in the same shell invocation.

#Text colours
GREEN=\033[0;32m
VIOLET=\033[0;35m
BLUE=\033[0;34m
BLUE_GREEN=\033[0;36m
RED=\033[0;31m
RED_BOLD=\033[1;31m
NC=\033[0m # No Color
#echo -e "${RED}text${NC}"

all: create_app

create_app: prog

# Run application that uses library
# The LD_LIBRARY_PATH is an environment variable that helps the user to set a path for shared libraries which can be made available during the execution.
# You need to point to the folder where library is located or you'll get the error:
#   a: libctest.so.1.0: cannot open shared object file: No such file or directory
# Use oneshell directive to execute variable export and program run in same shell invocation (or ./prog will run app with unmodified LD_LIBRARY_PATH). You could also just concatenate commands with ; or &&
.ONESHELL:
run_app:
	@export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(shell pwd)/../library/opt/lib
	@./prog

# Link the program for use with a shared library
#
# Library here is dynamically loaded/unloaded and linked during execution
#
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# This is not dynamically LINKED library (where libraries must be available during compile/link phase and
# the shared objects are not included into the executable component but are tied to the execution).
# Because of this, you don't need to:
#	- add library ctest with -lctest or
#	- to point to the folder where library is located -L$(shell pwd)/../library/opt/lib
#	(The reference to the library name -lctest refers to /opt/lib/libctest.so)
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#
# gcc parameters:
#	-rdynamic
#		Pass the flag -export-dynamic to the ELF linker, on targets that support it. This instructs the linker to add all symbols, not only used ones, to the dynamic symbol table. This
#		option is needed for some uses of "dlopen" or to allow obtaining backtraces from within a program.
#
#	-ldl is a library designation for the linker. It tells the linker to find and link a file named libdl.so (or sometimes libdl.a). It has the same effect as placing a full path to the library in question in the same position of the command line.
prog: prog.o
	gcc -rdynamic -ldl -o prog prog.o

# Compile program
# You need to add the location of header files (with -I) that define functions that library offers
prog.o: prog.c
	gcc -c -Wall -I$(shell pwd)/../library/ -o prog.o prog.c

clean:
	rm -f prog *.o
