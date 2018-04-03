#include <stdio.h>

/* this program returns takes in 0 arguments
 * and loops through numbers 1 to 9 to print a statement.
 */

int main( int argc, char *argv[] )  {
  for (int i=0; i < 10; i++) {
    printf("this is the %dth iteration of the loop\n", i);
  }
}
