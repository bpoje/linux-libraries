/* Filename: lib_mylib.c */
#include <stdio.h> 
#include "lib_mylib.h"

void fun(void) 
{ 
  printf("fun() called from a static library\n"); 
}

int myadd(int a, int b)
{
  printf("myadd(%d, %d) called from a static library\n", a, b);
  return a + b;
}

