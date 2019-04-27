#include<stdio.h>
#define Size 11

struct Problem_Set
{
    int id;
    int start_time;
    int end_time;
};

int main()
{
    FILE *file;
    file = fopen("input.txt","w");
    struct Problem_Set A[Size],temp;
    int i,j,index,small,S[Size],checking_time,n;///S[] for the of the resulted activity, n = used for resulted activity loop
    for(i=0;i<Size;i++)
    {
        A[i].id=i;
        printf("Enter Start Time\n");
        scanf("%d",&A[i].start_time);
        printf("Enter Finish Time\n");
        scanf("%d",&A[i].end_time);
        fprintf(file,"ID:%d Start_Time:%d  End_Time:%d\n",A[i].id+1,A[i].start_time,A[i].end_time);
        printf("\n");
    }
    fclose(file);

    for(i=0;i<Size;i++)
    {
        small=A[i].end_time;
        index=i;
        for(j=i+1;j<Size;j++)
        {
            if(A[j].end_time<small)
            {
                small=A[j].end_time;
                index=j;
            }
        }
        if(i!=index)
        {
            temp=A[index];
            A[index]=A[i];
            A[i]=temp;
        }
    }

    n=0;
    S[n]=0;///0 for taking 0th element
    checking_time=A[0].end_time;

    for(i=1;i<Size;i++)
    {
        if(A[i].start_time>=checking_time)
        {
            n++;
            S[n]=i;
            checking_time=A[i].end_time;
        }
    }
    printf("Sorted with End Time\n");
    for(i=0;i<Size;i++)
    {
        printf("ID:%d   Start_Time:%d   End_Time:%d\n",A[i].id,A[i].start_time,A[i].end_time);
    }
    file = fopen("output.txt","w");
    fprintf(file,"Total Activity is %d and they are\n",n+1);
    printf("\nTotal Activity is %d and they are\n",n+1);
    for(i=0;i<=n;i++)
    {
        j=S[i];
        printf("ID:%d   Start_Time:%d   End_Time:%d\n",A[j].id,A[j].start_time,A[j].end_time);
        fprintf(file,"ID:%d   Start_Time:%d   End_Time:%d\n",A[j].id,A[j].start_time,A[j].end_time);
    }
    fclose(file);
    return 0;
}
