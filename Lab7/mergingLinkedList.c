#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *l1 = NULL;
node *l2 = NULL;

node *createNode(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void createList(node **head, int data)
{
    if (*head == NULL)
    {
        *head = createNode(data);
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createNode(data);
    }
}

node *MergeList(node *p1, node *p2)
{
    node *result = NULL;
    node *temp = NULL;
    while (p1 != NULL || p2 != NULL)
    {
        node *new = NULL;
        if (p2 == NULL)
        {
            new = createNode(p1->data);
            p1 = p1->next;
        }
        else if (p1 == NULL)
        {
            new = createNode(p2->data);
            p2 = p2->next;
        }
        else if (p1->data < p2->data)
        {
            new = createNode(p1->data);
            p1 = p1->next;
        }
        else if (p2->data < p1->data)
        {
            new = createNode(p2->data);
            p2 = p2->next;
        }
        else if (p1->data == p2->data)
        {
            new = createNode(p1->data);
            p1 = p1->next;
        }

        if (result == NULL)
        {
            result = new;
            temp = result;
        }
        else
        {
            temp->next = new;
        }
        temp = new;
    }
    return result;
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
    createList(&l1, 1);
    createList(&l1, 3);
    createList(&l1, 5);
    createList(&l2, 2);
    createList(&l2, 4);
    createList(&l2, 6);

    node *result = MergeList(l1, l2);
    display(result);
    return 0;
}