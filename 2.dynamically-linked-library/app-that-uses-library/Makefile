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
#   ./prog: error while loading shared libraries: libctest.so.1: cannot open shared object file: No such file or directory
# Use oneshell directive to execute variable export and program run in same shell invocation (or ./prog will run app with unmodified LD_LIBRARY_PATH). You could also just concatenate commands with ; or &&
.ONESHELL:
run_app:
	@export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(shell pwd)/../library/opt/lib
	@./prog

# Compile & link the program for use with a shared library:
# The reference to the library name -lctest refers to /opt/lib/libctest.so
# gcc -Wall -L/opt/lib prog.c -lctest -o prog
#prog: prog.c
#	gcc -Wall -L$(shell pwd)/../library/opt/lib -lctest -I$(shell pwd)/../library/ -o prog prog.c

# Link the program for use with a shared library
# You need to add library ctest with -lctest and point to the folder where library located -L$(shell pwd)/../library/opt/lib
# or you'll get error: prog.c:(.text+0x10): undefined reference to `ctest1'
prog: prog.o
	gcc -Wall -L$(shell pwd)/../library/opt/lib -lctest -o prog prog.o

# Compile program
# You need to add the location of header files (with -I) that define functions that library offers
prog.o: prog.c
	gcc -c -Wall -I$(shell pwd)/../library/ prog.c -o prog.o

clean:
	rm -f prog prog.o
