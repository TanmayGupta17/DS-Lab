#include <stdio.h>

#define SIZE 10

void undirectedGraph(int graph[SIZE][SIZE], int src, int dest)
{
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}

void directedGraph(int graph[SIZE][SIZE], int src, int dest)
{
    graph[src][dest] = 1;
}

void printGraph(int graph[SIZE][SIZE], int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int vertices, edges;
    int src, dest;
    int graph[SIZE][SIZE];
    printf("Enter no of vertices: ");
    scanf("%d", &vertices);
    printf("Enter no of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }
    int choice;
    printf("1. Undirected Graph\n2. Directed Graph\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the edges(src dest):\n");
        for (int i = 0; i < edges; i++)
        {
            scanf("%d%d", &src, &dest);
            if (src >= vertices || dest >= vertices || src < 0 || dest < 0)
            {
                printf("Enter valid edges!");
                i--;
            }
            else
            {
                undirectedGraph(graph, src, dest);
            }
        }
        break;
    case 2:
        printf("Enter the edges(src dest):\n");
        for (int i = 0; i < edges; i++)
        {
            scanf("%d %d", &src, &dest);
            if (src >= vertices || dest >= vertices || src <= 0 || dest < 0)
            {
                printf("Enter valid edges!");
                i--;
            }
            else
            {
                directedGraph(graph, src, dest);
            }
        }
        break;
    }
    printGraph(graph, vertices);

    return 0;
}