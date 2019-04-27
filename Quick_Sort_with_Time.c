#include<stdio.h>
#include<time.h>
#define Size 100000

///took 0.083s to sort 100000 elements !best O(nlogn), worst O(n^2)
int Pivot_Correct_Position(int A[],int l,int r)
{
    int i,j,temp,pvt,pvt_rt_position;
    i=l-1;
    pvt=r;
    j=l;
    while(j<r)
    {
        if(A[j]<A[pvt])
        {
            i++;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
        j++;
    }
    pvt_rt_position=i+1;
    temp=A[pvt_rt_position];
    A[pvt_rt_position]=A[pvt];
    A[pvt]=temp;
    return pvt_rt_position;
}

void Quick_Sort(int A[],int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int pivot=Pivot_Correct_Position(A,left,right);
    Quick_Sort(A,left,pivot-1);
    Quick_Sort(A,pivot+1,right);
}


int main()
{
    FILE *file;
    int x,i,A[Size],j,temp;
    int time1;
    float T1;

    file = fopen("input.txt","w");
    if(file==NULL)
    {
        printf("Couldn't open Input File.\n");
        return;
    }

    srand(time(0));//to seed rand fn
    for(i=0;i<Size;i++)
    {
        x=rand();
        fprintf(file, "%d\n",x);
    }
    fclose(file);

    ///Scan from input file
    file = fopen("input.txt", "r");
    if(file==NULL)
    {
        printf("Couldn't open Input File.\n");
        return;
    }

    for(i=0;i<Size;i++)
    {
        fscanf(file, "%d", &A[i]);
    }
    fclose(file);


    time1 =clock();

    Quick_Sort(A,0,Size-1);

    time1 =clock();
    T1 = (float)time1/CLOCKS_PER_SEC;

    ///output in Output file
    file = fopen("output.txt","w");
    if(file==NULL)
    {
        printf("Couldn't open output File.\n");
        return;
    }

    for(i=0;i<Size;i++)
    {
        fprintf(file, "%d\n", A[i]);
    }
    fclose(file);

    printf("Quick Sort Took %f sec to Sort %d item\n",T1,Size);

    return 0;
}
