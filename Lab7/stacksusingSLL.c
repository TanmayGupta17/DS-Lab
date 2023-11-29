#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;

int pop()
{
    int data;
    if (head == NULL)
    {
        printf("stack is empty");
        return -99999999;
    }
    node *p;
    node *cur;
    for (cur = head; cur->next != NULL; cur = cur->next)
        ;
    data = cur->data;
    free(cur);
    return data;
}

void push(int val)
{
    node *cur;
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    for (cur = head; cur->next != NULL; cur = cur->next)
        ;
    cur->next = temp;
    temp->next = NULL;
}

void display()
{
    node *cur;
    for (cur = head; cur != NULL; cur = cur->next)
    {
        printf("%d\n", cur->data);
    }
}

int main()
{
    push(10);
    push(20);
    printf("%d\n", pop());
    push(30);
    display();

    return 0;
}