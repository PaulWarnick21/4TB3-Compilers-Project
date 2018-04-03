#include <stdio.h>

/* this program takes in 2 command line arguments
 * which must be integers and prints the sum of them.
 */

int main( int argc, char *argv[] )  {
     int A = 0;
     int B = 0;
     sscanf(argv[1],"%d", &A);
     sscanf(argv[2],"%d", &B);
     printf("%d \n", A + B);
}
