#include <bits/stdc++.h>
using namespace std;

const int max_size = 7;

int Graph[max_size][max_size];
char Colour[max_size];
int parent[max_size];

void DFS(int node)
{

    printf("%d--->>>\n",node);
    for (int i = 0; i < max_size; ++i)
    {
        printf("Parent[%d] = %d \n",i,parent[i]);
        printf("Color[%d] = %d \n",i,Colour[i]);
        printf("\n");

    }
    printf( "---------------------------------------------------\n");

    Colour[node] = 'g';
    for (int i = 0; i < max_size; ++i)
    {
        int adj = i;
        if (Graph[node][adj] == 1 and Colour[adj] == 'w')
        {
            parent[adj] = node;
            DFS(adj); //DFS(4)
        }
    }
    Colour[node] = 'b';
}

int main()
{
    printf("Enter the numbers of edges\n");
    int edgeCount;
    scanf("%d",&edgeCount);
    for (int i = 0; i < edgeCount; ++i)
    {
        printf("Enter the edges which add two nodes\n");
        int u, v;
        scanf("%d%d",&u,&v);

        Graph[u][v] = 1;
    }

    for (int i = 0; i < max_size; ++i)
    {
        Colour[i] = 'w';
        parent[i] = -1;
    }
    printf("Enter the sourceNode\n");
    int sourceNode;
    scanf("%d",&sourceNode);

    DFS(sourceNode); //DFS(1)
    parent0k,[sourceNode] = -1;

    printf("Final-->>\n");
    for (int i = 0; i < max_size; ++i)
    {
        printf("Parent[%d] = %d \n",i,parent[i]);
        printf("Color[%d] = %d \n",i,Colour[i]);
        printf("\n");

    }

    return 0;
}

