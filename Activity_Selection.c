#include<stdio.h>

void activities(int s[1000], int f[1000], int n)

{
    FILE *fp,*fw;


    fw=fopen("output.txt", "w");

	int i, j;

	printf ("\n\nAfter Selection Activities are:\n");
	fprintf (fw,"After Selection Activities are:\n");

	i = 1;

	printf("A[%d]=[%d,%d]\n",i,s[i],f[i]);
	fprintf (fw,"A[%d]= [%d,%d]\n",i,s[i],f[i]);

	for (j = 1; j<=n; j++)

	{

		if (s[j] >= f[i])

		{


			printf ("A[%d]=[%d,%d]\n",j,s[j],f[j]);
			fprintf (fw,"A[%d]=[%d,%d]\n", j,s[j],f[j]);

			i = j;

		}

	}
	printf("\n");
	fclose(fw);


}



int main()

{
    int i,n,s[1000],f[1000];
    FILE *fp,*fw;

    fp=fopen("input.txt","w");

    printf("Enter 1st & 2nd array limit:\n");
    scanf("%d",&n);

    printf("1st array Element are:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
    }


    fprintf(fp,"1st ARRAY Element are: ");
    for(i=1;i<=n;i++)
    {
        fprintf(fp,"%d\t",s[i]);
    }

    printf("2nd array Element are:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&f[i]);
    }

    fprintf(fp,"\n2st ARRAY Element are: ");
    for(i=1;i<=n;i++)
    {
        fprintf(fp,"%d\t",f[i]);
    }


    printf("\nBefore Selection Activities are:");
    fprintf(fp,"\n\nBefore Selection Activities are:");
    {
        for(i=1;i<=n;i++)
            {
                fprintf (fp,"\nA[%d]= [%d,%d]",i,s[i],f[i]);
                printf("\nA[%d]= [%d,%d]",i,s[i],f[i]);
            }
    }
    fclose(fp);

	activities(s, f, n);
