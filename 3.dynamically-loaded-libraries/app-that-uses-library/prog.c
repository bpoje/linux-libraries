#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <ctest.h>

int main(int argc, char **argv) 
{
   void *lib_handle;
   double (*fn)(int *);
   int x;
   char *error;

   //lib_handle = dlopen("/opt/lib/libctest.so", RTLD_LAZY);
   //lib_handle = dlopen("../shared-library/libctest.so.1.0", RTLD_LAZY);

   // You can run this from bash using:
   // $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/../library/opt/lib && ./prog
   lib_handle = dlopen("libctest.so.1.0", RTLD_LAZY);
   
   if (!lib_handle) 
   {
      fprintf(stderr, "a: %s\n", dlerror());
      exit(1);
   }

   fn = dlsym(lib_handle, "ctest1");
   if ((error = dlerror()) != NULL)  
   {
      fprintf(stderr, "b: %s\n", error);
      exit(1);
   }

   (*fn)(&x);
   printf("Value x=%d\n",x);

   fn = dlsym(lib_handle, "ctest2");
   if ((error = dlerror()) != NULL)  
   {
      fprintf(stderr, "b: %s\n", error);
      exit(1);
   }

   (*fn)(&x);
   printf("Value x=%d\n",x);

   dlclose(lib_handle);
   return 0;
}

