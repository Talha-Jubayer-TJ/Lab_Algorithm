#include<stdio.h>
#include<time.h>
#define Size 100000
///took 0.078s to sort 100000 elements !best,worst O(nlogn)
void Merge_Sort(int A[],int l,int m,int r)
{
    int i,j,k,l_s,r_s;
    l_s=m-l+1;
    r_s=r-m;
    int L[l_s],R[r_s];
    for(i=0;i<l_s;i++)
    {
        L[i]=A[l+i];
    }
    for(j=0;j<r_s;j++)
    {
        R[j]=A[m+1+j];
    }
    i=0,j=0,k=l;
    while(i<l_s && j<r_s)
    {
        if(L[i]<R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<l_s)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<r_s)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}

void Merge(int A[],int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int mid=left+(right-left)/2;
    Merge(A,left,mid);
    Merge(A,mid+1,right);
    Merge_Sort(A,left,mid,right);
}

int main()
{
    FILE *file;
    int x,i,A[Size];
    int time1;
    float T1;

    file = fopen("input.txt","w");
    if(file==NULL)
    {
        printf("Couldn't open Input File.\n");
        return;
    }

    srand(time(0));
    for(i=0;i<Size;i++)
    {
        x=rand();
        fprintf(file, "%d\n",x);
    }
    fclose(file);

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

    Merge(A,0,Size-1);

    time1 =clock();
    T1 = (float)time1/CLOCKS_PER_SEC;

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
    printf("Merge Sort Took %f sec to Sort %d item\n",T1,Size);

    return 0;
}
