#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
} node;

node *root = NULL;

void createTree()
{
    int n;
    printf("Enter no of nodes to add in the tree: ");
    scanf("%d", &n);
    int i = 0;
    while (i < n)
    {
        char dir[10];
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        printf("Enter directions: ");
        scanf("%s", &dir);

        node *curr = root;
        node *prev = curr;

        node *ptr = (node *)malloc(sizeof(node));
        ptr->data = data;
        ptr->left = NULL;
        ptr->right = NULL;

        if (root == NULL)
        {
            root = ptr;
        }
        else
        {
            int j = 0;
            while (dir[j] != '\0')
            {
                prev = curr;
                if (dir[j] == 'l')
                    curr = curr->left;
                else
                    curr = curr->right;
                j++;
            }
            if (dir[j - 1] == 'l')
                prev->left = ptr;
            else
                prev->right = ptr;
        }
        i++;
    }
}

void inorder()
{
    node *stack[20];
    int top = -1;
    node *temp = root;
    printf("Inorder: ");

    while (1)
    {
        while (temp != NULL)
        {
            stack[++top] = temp;
            temp = temp->left;
        }
        if (top > -1)
            temp = stack[top--];
        else
            break;

        printf("%d", temp->data);
        temp = temp->right;
    }
}

void Preorder()
{
    node *stack[20];
    int top = -1;
    node *temp = root;
    if (root == NULL)
        return;
    printf("Preorder: ");
    while (1)
    {
        while (temp != NULL)
        {
            printf("%d", temp->data);
            stack[++top] = temp;
            temp = temp->left;
        }
        if (top > -1)
        {
            temp = stack[top--];
        }
        else
            break;
        temp = temp->right;
    }
}

void postorder()
{
    node *s1[20];
    node *s2[20];
    int top1 = -1;
    int top2 = -1;
    s1[++top1] = root;
    printf("Postorder: ");
    while (top1 >= 0)
    {
        node *temp = s1[top1--];
        s2[++top2] = temp;
        if (temp->left != NULL)
            s1[++top1] = temp->left;
        if (temp->right != NULL)
            s1[++top1] = temp->right;
    }
    while (top2 >= 0)
    {
        node *temp = s2[top2--];
        printf("%d", temp->data);
    }
}

void parent(int ele)
{
    node *parent = NULL;
    node *stack[20];
    int top = -1;
    node *temp = root;
    if (root == NULL)
    {
        printf("Tree doesn't exist");
        return;
    }
    if (root->data == ele)
    {
        printf("No parent exists");
        return;
    }
    while (temp != NULL || top != -1)
    {
        while (temp != NULL)
        {
            stack[++top] = temp;
            if (temp->left && temp->left->data == ele)
            {
                parent = temp;
                break;
            }
            temp = temp->left;
        }
        if (top > -1)
        {
            temp = stack[top--];
            if (temp->right && temp->right->data == ele)
            {
                parent = temp;
                break;
            }
            temp = temp->right;
        }
    }
    if (parent == NULL)
    {
        printf("Parent not found");
        return;
    }
    else
    {
        printf("Parent(%d): %d", ele, parent->data);
    }
}

void depthTree()
{
    int ldepth = 0;
    int rdepth = 0;
    int depth;
    node *temp = root->left;
    node *curr = root->right;
    node *stack[20];
    int top = -1;
    while (temp != NULL || top != -1)
    {
        while (temp != NULL)
        {
            stack[++top] = temp;
            temp = temp->left;
            ldepth++;
        }
        if (top > -1)
        {
            temp = stack[top--];
            temp = temp->right;
        }
    }
    while (curr != NULL || top != -1)
    {
        while (curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->left;
            rdepth++;
        }
        if (top > -1)
        {
            curr = stack[top--];
            curr = curr->right;
        }
        if (top == -1)
            break;
    }
    if (ldepth > rdepth)
        depth = ldepth;
    else
        depth = rdepth;

    printf("Depth of Tree: %d", depth);
}

void ancestors(int ele)
{
    node *stack[20];
    int top = -1;
    node *temp = root;
    node *curr;
    while (temp != NULL || top != -1)
    {
        while (temp != NULL)
        {
            stack[++top] = temp;
            temp = temp->left;
        }
        if (top > -1)
        {

            temp = stack[top];
            if (temp->right == NULL && temp->left == NULL)
            {
                stack[top--];
            }
            if (temp->data == ele)
            {
                break;
            }

            temp = temp->right;
        }
    }
    while (top != -1)
    {
        curr = stack[top--];
        printf("%d", curr->data);
    }
}

int noOfLeafNodes()
{
    node *cur = root;
    node *stack[20];
    int top = -1;
    int count = 0;

    while (1 == 1)
    {
        while (cur != NULL)
        {
            stack[++top] = cur;
            cur = cur->left;
        }
        if (top > -1)
            cur = stack[top--];
        else
            break;

        if (cur->left == NULL && cur->right == NULL)
            count++;
        cur = cur->right;
    }
    return count;
}

int main()
{
    createTree();

    inorder();
    printf("\n");
    Preorder();
    printf("\n");
    postorder();
    printf("\n");
    int ele;
    printf("Enter the element who's parent need to be found: ");
    scanf("%d", &ele);
    parent(ele);
    printf("\n");
    depthTree();
    int ancestor;
    printf("Enter the element who's ancestors need to be found: ");
    scanf("%d", &ancestor);
    ancestors(ancestor);
    printf("\n");
    int leafnodes = noOfLeafNodes();
    printf("No. of leaf node: %d", leafnodes);

    return 0;
}
