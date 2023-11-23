#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int coeff;
    int power;
    struct node *next;
} node;

node *head1 = NULL;
node *head2 = NULL;

node *createNode(int power, int coeff)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->coeff = coeff;
    temp->power = power;
    temp->next = NULL;

    return temp;
}

void create(node **head, int power, int coeff)
{
    if (*head == NULL)
    {
        *head = createNode(power, coeff);
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createNode(power, coeff);
    }
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->power);
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
    while (p1 != NULL || p2 != NULL)
    {
        node *new = NULL;
        if (p1 == NULL)
        {
            new = createNode(p2->power, p1->coeff);
            p2 = p2->next;
        }

        else if (p2 == NULL)
        {
            new = createNode(p1->power, p1->coeff);
            p1 = p1->next;
        }

        else if (p1->power > p2->power)
        {
            new = createNode(p1->power, p1->coeff);
            p1 = p1->next;
        }

        else if (p2->power > p1->power)
        {
            new = createNode(p2->power, p2->coeff);
            p2 = p2->next;
        }

        else
        {
            new = createNode(p1->power, p1->coeff + p2->coeff);
            p1 = p1->next;
            p2 = p2->next;
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

node *Subtraction(node *p1, node *p2)
{
    node *result = NULL;
    node *temp = NULL;

    while (p1 != NULL || p2 != NULL)
    {
        node *new = NULL;
        if (p1 == NULL)
        {
            new = createNode(p2->power, p1->coeff);
            p2 = p2->next;
        }
        else if (p2 == NULL)
        {
            new = createNode(p1->power, p1->coeff);
            p1 = p1->next;
        }
        else if (p1->power > p2->power)
        {
            new = createNode(p1->power, p1->coeff);
            p1 = p1->next;
        }
        else if (p2->power > p1->power)
        {
            new = createNode(p2->power, p2->coeff);
            p2 = p2->next;
        }
        else
        {
            new = createNode(p1->power, p1->coeff - p2->coeff);
            p1 = p1->next;
            p2 = p2->next;
        }

        if (result == NULL)
        {
            result = new;
            temp = result;
        }
        else
        {
            temp->next = new;
            temp = temp->next;
        }
    }
    return result;
}

void evaluation(node *poly, int val)
{
    int result = 0;
    node *t = poly;
    if (poly == NULL)
        return;
    while (t != NULL)
    {
        result = t->coeff * pow(val, t->power) + result;
        t = t->next;
    }
    printf("%d\n", result);
}

node *Multiplication(node *p1, node *p2)
{
    node *result = NULL;
    node *temp = NULL;

    if (p1 == NULL)
    {
        return 0;
    }
    else if (p2 == NULL)
    {
        return 0;
    }
    while (p1 != NULL)
    {
        while (p2 != NULL)
        {
            node *new = NULL;
            new = createNode(p1->power + p2->power, p1->coeff * p2->coeff);
            p2 = p2->next;
            if (result == NULL)
            {
                result = new;
                temp = result;
            }
            else
            {
                temp->next = new;
                temp = temp->next;
            }
        }
        p1 = p1->next;
    }
    return result;
}

int main()
{
    create(&head1, 2, 4);
    create(&head1, 1, 3);
    create(&head1, 0, 7);
    create(&head2, 2, 2);
    create(&head2, 1, 2);
    create(&head2, 0, 2);

    printf("polynomial 1:\n");
    display(head1);

    printf("polynomial 2:\n");
    display(head2);

    node *sum = addPolynomials(head1, head2);
    printf("Sum of polynomial:\n ");
    display(sum);

    node *diff = Subtraction(head1, head2);
    printf("Difference of the polynoomial:\n ");
    display(diff);

    int val;
    printf("Enter the value to evaluate a function: ");
    scanf("%d", &val);
    evaluation(head1, val);

    node *multi = Multiplication(head1, head2);
    printf("Multiplication of polynomials: ");
    display(multi);
}