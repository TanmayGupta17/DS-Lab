#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int pow;
    struct node *next;
} node;

node *p1 = NULL;
node *p2 = NULL;

node *createNode(int coeff, int pow)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->coeff = coeff;
    temp->pow = pow;
    temp->next = NULL;
    return temp;
}

void create(int coeff, int pow, node **poly)
{
    if (*poly == NULL)
    {
        *poly = createNode(coeff, pow);
    }
    else
    {
        node *t = *poly;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = createNode(coeff, pow);
    }
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL)
        {
            printf("+");
        }
        temp = temp->next;
    }
    printf("\n");
}

node *addPolynomials(node *p1, node *p2)
{
    node *result = NULL;
    node *temp = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (result == NULL)
        {
            if (p1->pow > p2->pow)
            {
                result = createNode(p1->coeff, p1->pow);
                p1 = p1->next;
            }
            else if (p1->pow < p2->pow)
            {
                result = createNode(p2->coeff, p2->pow);
                p2 = p2->next;
            }
            else
            {
                result = createNode(p1->coeff + p2->coeff, p1->pow);
                p1 = p1->next;
                p2 = p2->next;
            }
            temp = result;
        }
        else
        {
            if (p1->pow > p2->pow)
            {
                temp->next = createNode(p1->coeff, p1->pow);
                p1 = p1->next;
            }
            else if (p1->pow < p2->pow)
            {
                temp->next = createNode(p2->coeff, p2->pow);
                p2 = p2->next;
            }
            else
            {
                temp->next = createNode(p1->coeff + p2->coeff, p1->pow);
                p1 = p1->next;
                p2 = p2->next;
            }
            temp = temp->next;
        }
    }

    while (p1 != NULL)
    {
        temp->next = createNode(p1->coeff, p1->pow);
        p1 = p1->next;
        temp = temp->next;
    }

    while (p2 != NULL)
    {
        temp->next = createNode(p2->coeff, p2->pow);
        p2 = p2->next;
        temp = temp->next;
    }

    return result;
}

int main()
{
    create(4, 2, &p1);
    create(3, 1, &p1);
    create(7, 0, &p1);
    create(4, 2, &p2);
    create(3, 1, &p2);
    create(7, 0, &p2);

    printf("Polynomial 1: ");
    display(p1);
    printf("Polynomial 2: ");
    display(p2);

    node *sum = addPolynomials(p1, p2);
    printf("Sum of the polynomials: ");
    display(sum);

    return 0;
}
