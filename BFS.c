#include <bits/stdc++.h>
using namespace std;

const int max_size = 6;

int Graph[max_size][max_size];
char Colour[max_size];
int Level[max_size];
int parent[max_size];

int main()
{
    printf("Enter the numbers of edges\n");
    int edgeCount;
    scanf("%d",&edgeCount);

    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        printf("Enter the edges which add two nodes\n");
        scanf("%d%d",&u,&v);

        Graph[u][v] = 1;
    }
    for(int i=0;i<max_size;i++)
    {
        for(int j=0;j<max_size;j++)
        {
            printf("%d  ",Graph[i][j]);
        }printf("\n");
    }



    printf("Enter the sourceNode\n");
    int sourceNode;
    scanf("%d",&sourceNode);
    //step-1
    for (int i = 0; i < max_size; ++i) {
        Colour[i] = 'w';
        Level[i] = 99999999;
        parent[i] = -1;
    }

    //step-2
    int Queue[max_size];
    int startP, endP;
    startP = 0;
    endP = 0;
    Queue[endP] = sourceNode;
    endP = endP + 1;
    Colour[sourceNode] = 'g';
    Level[sourceNode] = 0;
    parent[sourceNode] = -1;


    while (endP - startP > 0) {
        int u = Queue[startP];
        for (int i = 0; i < max_size; ++i) {
            int v = i;

            if (Graph[u][v] == 1 && Colour[v] == 'w') {
                Queue[endP] = v;
                endP = endP + 1;
                Colour[v] = 'g';
                Level[v] = Level[u] + 1;
                parent[v] = u;
            }
        }
        startP = startP + 1;
        Colour[u] = 'b';
    }

    for (int i = 0; i < max_size; ++i) {
        printf("Level  [%d] = %d\n",i,Level[i]);
        printf("Parent [%d] = %d\n",i,parent[i]);
        printf("Color  [%d] = %c\n",i,Colour[i]);
        printf("\n");
    }

    return 0;
}

