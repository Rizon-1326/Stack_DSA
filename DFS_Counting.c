#include<stdio.h>
#define max_size  6

char colour[max_size];
int parent[max_size],final[max_size],dis[max_size];
int run;
void DFS_Running(int u,int max,int Graph[max_size][max_size])
{
    colour[u]='g';
    run++;
    dis[u]=run;
    int v;

    for(int i=1;i<=max;i++)
    {
        if(Graph[u][i]==1)
        {
            v=i;
            if(colour[v]=='w')
            {
                parent[v]=u;
                DFS_Running(v,max,Graph);
            }
        }
    }
    colour[u]='b';
    run++;
    final[u]=run;
}

void DFS_main(int max,int Graph[max_size][max_size],int sourceNode)
{
    for(int i=1;i<=max;i++)
    {
        colour[i]='w';
        parent[i]=-1;
        final[i]=9999999;
        dis[i]=9999999;
    }

    run=0;
   DFS_Running(sourceNode,max,Graph);
    for(int i=1;i<=max;i++)
    {
        if(colour[i]=='w')
        {
            DFS_Running(i,max,Graph);
        }
    }
}

int main()
{
    printf("Enter the number of edges\n");
    int n;
    scanf("%d",&n);
    int Graph[max_size+1][max_size+1];
    for(int i=1;i<=max_size;i++)
    {
        for(int j=1;j<=max_size;j++)
        {
            Graph[i][j]=0;
        }
    }
    int max=max_size;
    printf("Enter the edges which add two vertices\n");
    for(int i=0;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        Graph[u][v]=1;
    }
    for(int i=1;i<=max;i++)
    {
        for(int j=1;j<=max;j++)
        {
            printf("%d  ",Graph[i][j]);
        }printf("\n");
    }
    int sourceNode;
    printf("Enter the sourceNode\n");
    scanf("%d",&sourceNode);
    DFS_main(max,Graph,sourceNode);
    for(int i=1;i<=max;i++)
    {
        printf("Parent[%d] --> %d\n",i,parent[i]);
        printf("Colour[%d] --> %c\n",i,colour[i]);
        printf("Discovery time of %d node is %d\n",i,dis[i]);
        printf("Final time of %d node is %d\n",i,final[i]);
        printf("\n\n\n");
    }
}
