#include<stdio.h>
#include<stdlib.h>

int s[100], j, res[100];
int a[100][100];
int ver,edge;

void dfs(int u, int ver)
{

    int v;
    s[u] = 1;
    for (v = 0; v < ver - 1; v++)
    {
        if (a[u][v] == 1 && s[v] == 0)
        {
            dfs(v, ver);
        }
    }
    j += 1;
    res[j] = u;
}

void topological_order(int ver)
{

    int u;
    for (int i = 0; i < ver; i++)
    {
        s[i] = 0;
    }
    j = 0;
    for (u = 0; u < ver; u++)
    {
        if (s[u] == 0)
        {
            dfs(u, ver);
        }
    }
    return;
}
int main()
{

    printf("Enter number of vertices\n");
    scanf("%d", &ver);
    int edges;
    printf("Enter the number of edges\n");
    scanf("%d",&edges);
    for(int i=1;i<=ver;i++)
    {
        for(int j=1;j<=ver;j++)
        {
            a[i][j]=0;
        }
    }
    printf("Enter the edges:\n");
   for(int i=0;i<edges;i++)
   {
        int u,v;
        scanf("%d%d",&u,&v);
        a[u][v]=1;
   }

    printf("Adjacency Matrix of the graph\n");
    for (int i=0; i<ver; i++)
    {
        for (int j=0; j<ver; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Topological order:\n");

    topological_order(ver);

    for (int i =ver; i >= 1; i--)
    {
        printf("%d ", res[i]);
    }

}
