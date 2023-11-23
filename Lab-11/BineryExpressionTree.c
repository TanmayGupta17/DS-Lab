#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    struct node *left;
    char data;
    struct node *right;
} node;

node *root = NULL;

node *createNode(char val)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

int operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    else
        return 0;
}

node *createExpressionTree(char postfix[])
{
    node *stack[20];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        node *temp = createNode(postfix[i]);
        if (operator(postfix[i]) == 0)
        {
            stack[++top] = temp;
        }
        else
        {
            temp->right = stack[top--];
            temp->left = stack[top--];
            stack[++top] = temp;
        }
    }
    return stack[top];
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    char postfix[] = "ab+c-d*";
    node *result = createExpressionTree(postfix);
    printf("Infix expression:\n ");
    inorder(result);
    return 0;
}