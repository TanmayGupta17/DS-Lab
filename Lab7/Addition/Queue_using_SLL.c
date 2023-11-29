#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;

void push(int x)
{
    node *p;
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = x;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    for (p = head; p->next != NULL; p = p->next)
        ;
    p->next = ptr;
}

int pop()
{
    int data;
    node *ptr = head;
    if (head == NULL)
    {
        printf("Queue is full");
        return -9999999;
    }
    head = head->next;
    data = ptr->data;
    free(ptr);
    return data;
}

void display()
{
    node *p;
    for (p = head; p != NULL; p = p->next)
    {
        printf("%d\n", p->data);
    }
}

int main()
{
    push(10);
    push(20);
    pop();
    push(30);
    display();
}
