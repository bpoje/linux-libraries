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

all: create_library deploy_library

create_library: libctest.so.1.0

deploy_library: opt/lib/libctest.so

opt/lib/libctest.so:
	mkdir -p opt/lib
	cp -f libctest.so.1.0 opt/lib
	ln -sfv $(shell pwd)/opt/lib/libctest.so.1.0 opt/lib/libctest.so.1
	ln -sfv $(shell pwd)/opt/lib/libctest.so.1 opt/lib/libctest.so

# Compile object code
# -Wall: include warnings. See man page for warnings specified.
# -fPIC: Compiler directive to output position independent code, a characteristic required by shared libraries. Also see "-fpic".
ctest1.o: ctest1.c
	gcc -Wall -fPIC -c ctest1.c

# Compile object code
# -Wall: include warnings. See man page for warnings specified.
# -fPIC: Compiler directive to output position independent code, a characteristic required by shared libraries. Also see "-fpic".
ctest2.o: ctest2.c
	gcc -Wall -fPIC -c ctest2.c

# Create library (link object code)
# -shared: Produce a shared object which can then be linked with other objects to form an executable.
# -Wl,options: Pass options to linker.
#  In this example the options to be passed on to the linker are: "-soname libctest.so.1".
#  The name passed with the "-o" option is passed to gcc.
# Option -o: Output of operation. In this case the name of the shared object to be output will be "libctest.so.1.0" 
libctest.so.1.0: ctest1.o ctest2.o
	gcc -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0 ctest1.o ctest2.o

clean:
	rm -f *.o libctest.so* ./opt/lib/libctest.so*
	rmdir -p opt/lib/
