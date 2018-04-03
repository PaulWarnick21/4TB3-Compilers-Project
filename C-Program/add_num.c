#include <stdio.h>

/* this program returns takes in 2 arguments
 * which must be integers and returns the sum of them.
 */

int main( int argc, char *argv[] )  {

   if( argc == 3 ) {
     int A = 0;
     int B = 0;
     sscanf(argv[1],"%d", &A);
     sscanf(argv[2],"%d", &B);

     printf("%d \n", A + B);
   }
}
