#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;
int queue[50];

int main()
{
    int node;
    int i = 1; // starting node from the graph
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int adjacency[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("%d", i);
    visited[i] = 1;
    queue[++rear] = i; // Enqueue the element for further exploration
    while (front != rear)
    {
        node = queue[++front];
        for (int j = 0; j < 7; j++)
        {
            if (adjacency[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                queue[++rear] = j;
            }
        }
    }
    return 0;
}
