#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000

int main ()
{

    int num[SIZE],i,j, temp = 0, fR;

    srand(time(0));
    for (fR = 0; fR < SIZE; fR++){
        num[fR] = rand();
    }

    FILE *fp, *fw ;
    fp = fopen ("D:\\input.txt", "w");

    for (fR = 0; fR < SIZE; fR++){
        fprintf (fp, "%d\n", num[fR]);
    }
    fclose (fp);

    // Sorting
    clock_t t;
    t = clock ();

    for (fR = 1 ; fR < SIZE  ; fR++) {\
        temp = num[fR];
        i = fR - 1;

        while ( temp < num[i] && i >=0) {
         num[i+1] = num [i];
         i--;
        }
        num [i+1] = temp ;
    }

    t = clock()  ;
    double  time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Insertion sort took %f seconds to execute \n", time_taken);


    fw = fopen("D:\\output.txt", "w");

     for (fR = 0; fR < SIZE ; fR++){
         fprintf (fw, "%d\n", num[fR]);
     }
     fclose (fw);

    return 0;

}
