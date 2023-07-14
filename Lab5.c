#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int adjm[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int stack[MAX];
int top = -1;
int vrt;
int i = 0, j = 0;
void create_graph()
{
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vrt);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vrt; i++)
    {
        for (j = 0; j < vrt; j++)
        {
            scanf("%d", &adjm[i][j]); 
        }
    }
}

void display_graph()
{
    int i, j;
    printf("The adjacency matrix is:\n");
    for (i = 0; i < vrt; i++)
    {
        for (j = 0; j < vrt; j++)
        {
            printf("%d ", adjm[i][j]); 
        }
        printf("\n");
    }
}

void bfs(int stvr)
{
    int i, ctvr;

    visited[stvr] = 1;    // mark the starting vertex as visited
    queue[++rear] = stvr; // add the starting vertex to the queue

    printf("\nBFS traversal starting from vertex %d: \n", stvr);
    while (front != rear)
    {                                        // loop until the queue becomes empty
        ctvr = queue[++front];     // remove the front element from the queue and set it as the current vertex
        printf("%c ", ctvr + 'A'); // print the current vertex as an alphabet

        // add the adjacent vertices of the current vertex to the queue if they are not already visited
        for (i = 0; i < vrt; i++)
        {
            if (adjm[ctvr][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

void dfs(int stvr)
{
    int i, ctvr;

    visited[stvr] = 1;   // mark the starting vertex as visited
    stack[++top] = stvr; // add the starting vertex to the stack

    printf("DFS traversal starting from vertex %d: ", stvr);
    while (top != -1)
    {                                        // loop until the stack becomes empty
        ctvr = stack[top--];       // remove the top element from the stack and set it as the current vertex
        printf("%c ", ctvr + 'A'); // print the current vertex as an alphabet

        // add the adjacent vertices of the current vertex to the stack if they are not already visited
        for (i = 0; i < vrt; i++)
        {
            if (adjm[ctvr][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }
    printf("\n");
}

int main()
{
    int choice, stvr;
    while (1)
    {
        printf("\n1. Create Adjacency matrix\n2. Display matrix\n3. BFS traversal\n4. DFS traversal\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_graph();
            break;
        case 2:
            display_graph();
            break;
        case 3:
            printf("Enter the starting vertex for BFS traversal: ");
            scanf("%d", &stvr);
            if (stvr >= 0 && stvr < vrt)
            {
                // initialize visited array for BFS
                for (i = 0; i < MAX; i++)
                {
                    visited[i] = 0;
                }
                bfs(stvr);
            }
            else
            {
                printf("Invalid starting vertex.\n");
            }
            break;
        case 4:
            printf("Enter the starting vertex for DFS traversal: ");
            scanf("%d", &stvr);
            if (stvr >= 0 && stvr < vrt)
            {
                // initialize visited array for DFS
                for (i = 0; i < MAX; i++)
                {
                    visited[i] = 0;
                }
                dfs(stvr);
            }
            else
            {
                printf("Invalid starting vertex.\n");
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
