#include <stdio.h>
#define MAX 100
int graph[MAX][MAX], mst[MAX], visited[MAX];
int n, e;
void create_graph();
void display();
void prims();
int main()
{
    int option;
    do
    {
        printf("\n\n1. Create graph");
        printf("\n2. Display");
        printf("\n3. Find MST");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            create_graph();
            break;
        case 2:
            display();
            break;
        case 3:
            prims();
            break;
        case 4:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid choice!");
        }
    } while (option != 4);
    return 0;
}
void create_graph()
{
    int i, j, wt;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the number of edges: ");
    scanf("%d", &e);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    printf("\nEnter the details of each edge with weight(Edge---edge weight): \n");
    for (i = 0; i < e; i++)
    {
        int u, v;
        printf("\nEdge %d: ", i + 1);
        scanf("%d%d%d", &u, &v, &wt);
        graph[u][v] = graph[v][u] = wt;
    }
}
void display()
{
    int i, j;
    printf("\nAdjacency matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}
void prims()
{
    int i, j, k, u, v, min, total_weight = 0;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        mst[i] = -1;
    }
    visited[0] = 1;
    for (i = 1; i < n; i++)
    {
        u = 0;
        v = i;
        min = graph[u][v];
        for (j = 0; j < n; j++)
        {
            if (visited[j])
            {
                for (k = 0; k < n; k++)
                {
                    if (!visited[k] && graph[j][k])
                    {
                        if (graph[j][k] < min)
                        {
                            min = graph[j][k];
                            u = j;
                            v = k;
                        }
                    }
                }
            }
            visited[v] = 1;
            if (mst[u] == -1)
            {
                mst[u] = v;
            }
            else
            {
                mst[v] = u;
            }
            total_weight += min; 
        }
        printf("\nMinimum Spanning Tree: ");
        for (i = 0; i < n; i++)
        {
            if (mst[i] != -1)
            {
                printf("%c - %c . ", i + 'A', mst[i] + 'A');
            }
        }
        printf("\n\nTotal weight of the MST: %d ", total_weight);
    }
}