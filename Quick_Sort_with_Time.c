#include<stdio.h>
#include<time.h>
void quicksort(int number[1000],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){

            while(number[i]<=number[pivot]&&i<last)
            i++;
            while(number[j]>number[pivot])
            j--;
            if(i<j){
                    temp=number[i];
                    number[i]=number[j];
                    number[j]=temp;
            }
        }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
   int i, n, number[1000];
   FILE *fp, *fw;
    printf("\nPrinting UnSorted Numbers\n");

    fp=fopen("input.txt", "w");

     printf("Enter number of elements limit: \n");
               scanf("%d", &n);


               printf("\nbefore sorting: \n");
                srand(time(0));



             for (i = 0; i < n; i++){
                number[i]=rand();
             }

                for (i = 0; i < n; i++){
                    fprintf(fp,"%d\n", number[i]);
                    printf("%d\n",number[i]);
                }

    fclose(fp);

     clock_t t;
    t = clock ();

    quicksort(number,0,n-1);

     t = clock()  ;
    double  time_taken = ((double)t)/CLOCKS_PER_SEC;


   printf("\nOrder of Sorted elements: ");

       fw=fopen("output.txt", "w");

       for (i=0;i<n;i++){
                    fprintf(fw,"%d\n", number[i]);
                    printf("\n%d",number[i]);
                }

    fclose(fw);
    printf("\n\n***** QUIC sort took %f seconds to execute ******\n\n", time_taken);

   return 0;
}
