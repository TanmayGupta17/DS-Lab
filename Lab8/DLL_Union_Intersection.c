#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
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

void Union(node **p1, node *p2)
{
    if (*p1 == NULL)
    {
        *p1 = p2;
        return;
    }
    node *temp = *p1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p2;
    if (p2 != NULL)
        p2->prev = temp;
}
// void Union(node **p1, node *p2)
// {
//     if (*p1 == NULL)
//     {
//         *p1 = p2;
//         return;
//     }

//     node *temp = *p1;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }

//     // Connect the second list to the first list
//     temp->next = p2;
//     if (p2 != NULL)
//     {
//         p2->prev = temp;
//     }
// }

node *Intersection(node *p1, node *p2)
{
    node *result = NULL;
    node *temp = NULL;
    while (p1 != NULL || p2 != NULL)
    {
        node *new = NULL;
        if (p1 == NULL)
        {
            new = createNode(p2->data);
            p2 = p2->next;
        }
        else if (p2 == NULL)
        {
            new = createNode(p1->data);
            p1 = p1->next;
        }
        else if (p1->data == p2->data)
        {
            new = createNode(p1->data);
            if (result == NULL)
            {
                result = new;
                temp = result;
            }
            else
            {
                temp->next = new;
                new->prev = temp;
                temp = temp->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->data < p2->data)
        {
            p1 = p1->next;
        }
        else if (p1->data > p2->data)
        {
            p2 = p2->next;
        }
    }
    return result;
}

// node *Intersection(node *p1, node *p2)
// {
//     node *result = NULL;
//     node *temp = NULL;

//     while (p1 != NULL && p2 != NULL)
//     {
//         if (p1->data == p2->data)
//         {
//             node *newNode = createNode(p1->data);
//             if (result == NULL)
//             {
//                 result = newNode;
//                 temp = result;
//             }
//             else
//             {
//                 temp->next = newNode;
//                 newNode->prev = temp;
//                 temp = newNode;
//             }
//             p1 = p1->next;
//             p2 = p2->next;
//         }
//         else if (p1->data < p2->data)
//         {
//             p1 = p1->next;
//         }
//         else
//         {
//             p2 = p2->next;
//         }
//     }

//     return result;
// }

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
    createList(&l1, 2);
    createList(&l1, 8);
    createList(&l2, 2);
    createList(&l2, 5);
    createList(&l2, 8);

    node *result = Intersection(l1, l2);
    display(result);
    printf("\n");
    Union(&l1, l2);
    display(l1);
    return 0;
}