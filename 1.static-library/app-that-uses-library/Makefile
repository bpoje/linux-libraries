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

run_app:
	./prog

#Link the compiled program to the static library. Note that -L. is used to tell that the static library is in current folder (See this for details of -L and -l options).
prog: prog.o
	@echo -e "${VIOLET}Link the compiled app that uses library to the static library${NC}"
	
	# Option 1: copy static library to this folder and link it to executable
	#cp $(shell pwd)/../library/lib_mylib.a .
	#gcc -o prog prog.o -L. -l_mylib

	# Option 2: tell linker where to find static library
	gcc -o prog prog.o -L$(shell pwd)/../library/ -l_mylib

# Compile program
prog.o: prog.c
	@echo -e "${VIOLET}Compile the app that uses library${NC}"
	gcc -c prog.c -o prog.o

clean:
	rm -f prog *.o *.a
