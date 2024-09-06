# Notes:
# Symbol @ means don't print command
# The .ONESHELL: directive allows to write multiple line recipes to be executed in the same shell invocation.

MY_VAR := $(shell pwd)

#Text colours
GREEN=\033[0;32m
VIOLET=\033[0;35m
BLUE=\033[0;34m
BLUE_GREEN=\033[0;36m
RED=\033[0;31m
RED_BOLD=\033[1;31m
NC=\033[0m # No Color
#echo -e "${RED}text${NC}"

all: create_library

.ONESHELL:
create_library: lib_mylib.a

# Compile library file
lib_mylib.o: lib_mylib.c
	@echo -e "${VIOLET}Compile library files${NC}"
	gcc -c lib_mylib.c -o lib_mylib.o

# Create static library. This step is to bundle multiple object files in one static library (see ar for details). The output of this step is static library.
#
# r   Insert the files member... into archive (with replacement). This operation differs from q in that any previously existing members are deleted if their
#     names match those being added.
#
# c   Create the archive.  The specified archive is always created if it did not exist, when you request an update.  But a warning is issued unless you specify
#     in advance that you expect to create it, by using this modifier.
#
# s   Add an index to the archive, or update it if it already exists.  Note this command is an exception to the rule that there can only be one command letter,
#     as it is possible to use it as either a command or a modifier.  In either case it does the same thing.
#
lib_mylib.a: lib_mylib.o
	@echo -e "${VIOLET}Create static library${NC}"
	ar rcs lib_mylib.a lib_mylib.o

clean:
	rm -f *.{o,a}
