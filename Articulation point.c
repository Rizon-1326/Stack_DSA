
#include<stdio.h>
#include<stdlib.h>
int num_of_vertices;
char color[100];
int finishing_time[100];
int discovery_time[100];
int prev[100];
int low[100];
int time=0;
int AP[100];
int Children[100];

void creat_Matrix(int AdjMatrix[][num_of_vertices],int connection[][2],int num_of_edges)
{ for(int i=1;i<=num_of_edges;i++)
   {
     int x=connection[i][0];
     int y=connection[i][1];

     AdjMatrix[x][y]=1;
    
   } 
   for(int i=1;i<=num_of_vertices;i++){
   for(int j=1;j<=num_of_vertices;j++)
   {if(AdjMatrix[i][j]!=1)
     AdjMatrix[i][j]=0;
     }
     } 
}

void Dfs(int G[][num_of_vertices])
{ 

   
  for(int i=1;i<=num_of_vertices;i++)
  { 
    color[i]='w';
    prev[i]=-1;
    low[i]=discovery_time[i]=finishing_time[i]=100000;
    }

for(int i=1;i<=num_of_vertices;i++)
{
    if(color[i]=='w')
    {
        DFS_visit(G,i);
    }
}



}
void printAdjMatrix(int Adj[][num_of_vertices])
{
  
   printf("\n");
    for (int i = 1; i <=num_of_vertices; i++) {
        for (int j = 1; j <=num_of_vertices; j++) {
  
       
            printf("%d\t ", Adj[i][j]);
        }
        printf("\n");
    }
}


void DFS_visit(int G[][num_of_vertices],int i)
{ 
    color[i]='g';
    discovery_time[i]=++time;
    low[i]=discovery_time[i];
     for(int j=1;j<=num_of_vertices;j++)
    {   if(G[i][j]==1)
    {
        Children[i]++;
    }
        if(G[i][j]==1&&color[j]=='w')
          {   prev[j]=i;
              
              DFS_visit(G,j);
              if(low[j]>=discovery_time[i])
              {
                AP[j]=1;
              }

              if(low[j]<low[i])
              {
                low[i]=low[j];
              }
          }

         else if(discovery_time[j]<low[i])
          {low[i]=discovery_time[j];}
          else 
          continue;
    }

    color[i]='b';
    finishing_time[i]=++time;
 
}
int main()
{
    printf("How many vertices do you want?\n");
    scanf("%d",&num_of_vertices);
   int num_of_edges;
   printf("Number of total connection-\n");
   scanf("%d",&num_of_edges);
   int conect[num_of_edges][2];
   printf("Give connected vertices(in integer according to given index)with weight of edge\n" );
   for(int i=1;i<=num_of_edges;i++)
   {
    scanf("%d%d",&conect[i][0],&conect[i][1]);
    
   }

   int AdjMatrix[num_of_vertices][num_of_vertices];
   
   creat_Matrix(AdjMatrix,conect,num_of_edges);

   
   Dfs(AdjMatrix);

   //printAdjMatrix(AdjMatrix);

  for(int i=1;i<=num_of_vertices;i++)
   {
    if(prev[i]==-1 && Children[i]>1)
    {
        AP[i]=1;
    }
   }
   
   for(int i=1;i<=num_of_vertices;i++)
   {
    if(AP[i]==1)
     printf("%d\t",i);
   }
}
