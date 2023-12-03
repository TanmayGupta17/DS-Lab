#include <stdio.h>

#define MAX_VERTICES 10

// Function to add an edge for directed graph
void addDirectedEdge(int graph[MAX_VERTICES][MAX_VERTICES], int src, int dest)
{
    graph[src][dest] = 1;
}

// Function to add an edge for undirected graph
void addUndirectedEdge(int graph[MAX_VERTICES][MAX_VERTICES], int src, int dest)
{
    graph[src][dest] = 1;
    graph[dest][src] = 1; // For undirected graph, we add edge in both directions
}

// Function to print the adjacency matrix
void printGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices)
{
    printf("Adjacency Matrix Representation:\n");
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
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            graph[i][j] = 0; // Initialize the matrix with zeros
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src >= vertices || dest >= vertices || src < 0 || dest < 0)
        {
            printf("Invalid edge! Please enter valid vertices.\n");
            i--;
        }
        else
        {
            // Uncomment one of the following lines based on the type of graph you want (directed or undirected)
            // addDirectedEdge(graph, src, dest); // For directed graph
            addUndirectedEdge(graph, src, dest); // For undirected graph
        }
    }

    printGraph(graph, vertices);

    return 0;
}
