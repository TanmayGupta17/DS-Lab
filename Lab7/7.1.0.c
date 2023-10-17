// insert in the beginning
// insert at the end
// insert at the given position
// delete in the beginning
// delete from the end

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void createList()
{
    if (head == NULL)
    {
        int n;
        printf("Enter number of nodes: ");
        scanf("%d", &n);
        if (n != 0)
        {
            int data;
            Node *newNode;
            Node *current;
            newNode = malloc(sizeof(Node));
            head = newNode;
            current = head;
            printf("Enter start data: ");
            scanf("%d", &data);
            head->data = data;
            for (int i = 2; i <= n; i++)
            {
                newNode = malloc(sizeof(Node));
                current->next = newNode;
                printf("Enter data: ");
                scanf("%d", &data);
                newNode->data = data;
                current = current->next;
            }
            current->next = NULL;
            printf("List is created\n");
        }
    }
    else
        printf("List already created\n");
}

void TraverseLinkedList()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void insertAtFirst(int val)
{
    Node *p = (Node *)malloc(sizeof(struct Node));
    p->data = val;
    p->next = head;
    head = p;
    return;
}

void insertAtIndex(int val, int index)
{
    Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    Node *p = head;
    ptr->data = val;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return;
}

void inserAtEnd(int val)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = val;
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
}

void DeleteAtFirst()
{
    Node *p = head;
    head = head->next;
    free(p);
    return;
}

void DeleteAtEnd()
{
    Node *ptr = head;
    Node *p = head->next;
    while (p->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(p);
}

void DeleteElement(int val)
{
    Node *ptr = head;
    Node *p = head->next;
    while (p->data != val)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);
}

void sorting()
{
    Node *p = head;
    Node *q = head->next;
    while (p->next != NULL)
    {
        if (p->data > q->data)
        {
            int temp = p->data;
            p->data = q->data;
            q->data = temp;
        }
        else if ((p->data < q->data) && q->next != NULL)
        {
            q = q->next;
        }
        else
        {
            p = p->next;
            q = p;
            q = q->next;
        }
    }
}

void deleteAlt()
{
    int m = 0;
    Node *current = head->next;
    Node *ptr = head;
    while (current != NULL)
    {
        if (m == 0)
        {
            ptr->next = current->next;
            Node *temp = current;
            current = current->next;
            free(temp);
            m = -1;
        }
        else
        {
            m = 0;
            ptr = current;
            current = current->next;
        }
    }
}

int main()
{

    TraverseLinkedList();
    insertAtFirst(91);
    insertAtIndex(20, 1);
    inserAtEnd(17);
    sorting();
    DeleteElement(20);
    TraverseLinkedList();
}
