#include <stdio.h>
#include <conio.h>
#define MAX 10
int size;
void bfs(int adj[][size], int visited[], int start){
	int queue[size], rear=-1, front=-1, i, k;
	for(k=0;k<size;k++){
		visited[k]=0;
	}
	queue[++rear]=start;
	++front;
	visited[start]=1;
	while(rear>=front){
		start=queue[front++];
		printf("\nNew visit: %c ",start + 65);
		for(i=0;i<size;i++){
			if(adj[start][i] && visited[i]==0){
				queue[++rear]=i; 
				visited[i]=1;
			}
		}
	}
}
void dfs(int adj[][size], int visited[], int start){
	int stack[size];
	int top=-1, i, k;
	for(k=0;k<size;k++){
		visited[k]=0;
	}
	stack[++top]=start;
	visited[start]=1;
	while(top!=-1){
		start=stack[top--];
		printf("\nNew visit: %c ",start + 65);
		for(i=0;i<size;i++){
			if(adj[start][i] && visited[i]==0){
				stack[++top]=i;
				visited[i]=1;
			}
		}
	}
}
void main(){
	int visited[MAX]={0};
	int adj[MAX][MAX], i, j;
	int ch;
	printf("General instruction for adjacency matrix: enter 1 if there is connection else enter 0.\n\n");
	printf("Input number of nodes: (max 10):"); scanf("%d",&size);
	int o=1;
	while(o!=0){
		printf("\n1.Input adjacency matrix\n2.Perform BFS\n3.Perform DFS\n0.Exit:");
		scanf("%d",&o);
		switch(o){
			case 1:
				for(int i=0;i<size;i++){
					printf("\nFor node %d:",i);
					for(int j=0;j<size;j++){
						printf("Connection with %d:",j);
						scanf("%d",&adj[i][j]);
					}
				}
				printf("\nThe adjacency matrix is:\n");
				for(int i=0;i<size;i++){
					for(int j=0;j<size;j++){
						printf(" %d ",adj[i][j]);
					}
					printf("\n");
				}break;
			case 2: printf("BFS from node A:\n"); bfs(adj,visited,0); break;
			case 3: printf("DFS from node A:\n"); dfs(adj,visited,0); break;
			case 0: printf("\n\n---------------E X I T---------------"); break;
			default: printf("\nINVALID INPUT\n");
			
		}
	}
}