/* filename: driver.c  */
#include "lib_mylib.h"
#include <stdio.h>

int main(int argc, char **argv)
{ 
  fun();

  int r = myadd(1, 2);
  printf("in app result is: %d\n", r);

  return 0;
}
