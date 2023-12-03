#include <stdio.h>
#define SIZE 20

int top = -1;
int stack[SIZE];

int main()
{
    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int adjacency[SIZE][SIZE] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("%d", i);
    visited[i] = 1;
    stack[++top] = i;
    while (top > -1)
    {
        node = stack[top--];
        for (int j = 0; j < 7; j++)
        {
            if (adjacency[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                stack[++top] = j;
            }
        }
    }
    return 0;
}