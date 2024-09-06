# Static, Shared Dynamic and Loadable Linux Libraries

Test of simple **Static**, Shared Dynamic and Loadable Linux Libraries.

Source: http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html

## Notes

### Linux Library Types
There are two Linux C/C++ library types which can be created:
1. Static libraries (.a): Library of object code which is linked with, and becomes part of the application.
2. Dynamically linked shared object libraries (.so): There is only one form of this library but it can be used in two ways.
    1. Dynamically linked at run time. The libraries must be available during compile/link phase. The shared objects are not included into the executable component but are tied to the execution.
    2. Dynamically loaded/unloaded and linked during execution (i.e. browser plug-in) using the dynamic linking loader system functions.

### Library naming conventions
    Libraries are typically named with the prefix "lib". This is true for all the C standard libraries.
    When linking, the command line reference to the library will not contain the library prefix or suffix.

    Consider the following compile and link command: gcc src-file.c -lm -lpthread
    The libraries referenced in this example for inclusion during linking are the math library ("m") and the thread library ("pthread").
    They are found in /usr/lib/libm.a and /usr/lib/libpthread.a.

Note: The GNU compiler now has the command line option "-pthread" while older versions of the compiler specify the pthread library explicitly with "-lpthread". Thus now you are more likely to see gcc src-file.c -lm -pthread 

### Commands
- nm: list symbols: object files, archive library and shared library
- readelf: list symbols in shared library
- ar - create, modify, and extract from archives
- ranlib - generate index to archive
- nm - list symbols from object files
- ld - Linker
- ldconfig - configure dynamic linker run-time bindings
    ldconfig -p : Print the lists of directories and candidate libraries stored in the current cache.
    i.e. /sbin/ldconfig -p |grep libGL
- ldd - print shared library dependencies
- gcc/g++ - GNU project C and C++ compiler
- man page to:
    ld.so - a.out dynamic linker/loader
