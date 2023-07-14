#include<stdio.h>
#include<conio.h>

int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];

int main()
{
printf("\n Enter the number of nodes:");
scanf("%d",&n);
printf("\n Enter the adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&cost[i][j]);
visited[0]=1;
printf("\n");
while(ne<n)
{
min=999;
for(i=0;i<n;i++)
{
if(visited[i]==1)
{
for(j=0;j<n;j++)
{
if(visited[j]==0 && cost[i][j]<min && cost[i][j]!=0)
{
min=cost[i][j];
a=i;
b=j;
}
}
}
}
if(visited[b]==0)
{
printf("Edge %d (%d,%d) cost is %d\n",ne++,a,b,min);
mincost+=min;
visited[b]=1;
}
cost[a][b]=cost[b][a]=999;
}
printf("\nThe minimum cost is %d",mincost);
getch();
}