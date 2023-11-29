#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

node *X1 = NULL;
node *X2 = NULL;

node *createNode(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    return ptr;
}

void createList(node **head, int data)
{
    node *new = createNode(data);
    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
}

void Concatenate(node **p1, node *p2)
{
    if (*p1 == NULL)
    {
        *p1 = p2;
    }
    node *temp = *p1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = p2;
    if (X2 != NULL)
        p2->prev = temp;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        if (temp->next != NULL)
            printf("-> ");
        temp = temp->next;
    }
}

int main()
{
    createList(&X1, 1);
    createList(&X1, 2);
    createList(&X1, 3);
    createList(&X2, 4);
    createList(&X2, 5);
    createList(&X2, 6);

    Concatenate(&X1, X2);
    display(X1);
    return 0;
}