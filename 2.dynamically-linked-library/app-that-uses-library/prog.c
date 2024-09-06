#include <stdio.h>
#include <ctest.h>

int main()
{
   int x;
   ctest1(&x);
   printf("Value of x=%d\n", x);

   ctest2(&x);
   printf("Value of y=%d\n", x);

   return 0;
}

