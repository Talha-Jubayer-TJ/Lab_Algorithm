#include<stdio.h>
#define Size 5
int Q[Size],A[Size][Size],Visited[Size],head=0,tail=0;

FILE *file;

void En_Q(int x)
{
    Q[tail]=x;
    tail++;
}

void De_Q()
{
    int res,i;
    res=Q[head];
    for(i=0;i<tail-1;i++)
    {
        Q[i]=Q[i+1];
    }
    printf("%d ",res);
    fprintf(file,"%d ",res);
    tail--;
}

int Is_Empty()
{
    if(head==tail){
        return 1;
        }
    else
        return 0;
}

int Input()
{
    FILE *input;
    input=fopen("inpt.txt","w");
    int i,j,st_vtx;
    fprintf(input,"No of Vertex : %d\n",Size);
    printf("No of Vertex:%d\n",Size);
    printf("Enter Vetex in Matrix Form:\n");
    for(i=0;i<Size;i++) ///i is row
    {
        for(j=0;j<Size;j++) ///j is colum
        {
            scanf("%d",&A[i][j]);
            fprintf(input,"%d ",A[i][j]);
        }
        fprintf(input,"\n");
        Visited[i]=0;
    }
    printf("Enter Start Vertex:\n");
    scanf("%d",&st_vtx);
    fprintf(input,"Start Vertex : %d\n",st_vtx);
    fclose(input);
    return st_vtx;
}

void BFS(int st_vtx)
{
    int j;  ///j is collum
    En_Q(st_vtx);
    while(Is_Empty()!=1)
    {
        st_vtx=Q[head];
        Visited[st_vtx]=1;
        for(j=0;j<Size;j++)
        {
            if(A[st_vtx][j]==1 && Visited[j]==0)
            {
                En_Q(j);
                Visited[j]=1;
            }
        }
        De_Q();
    }
}

int main()
{
    int s;
    s=Input();
    file=fopen("otpt.txt","w");
    fprintf(file,"Start Vertex:%d\n",s);
    BFS(s);
    fclose(file);
}
