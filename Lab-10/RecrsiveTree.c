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


node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    if(x==-1)
    return NULL;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();

    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}



void inorder(node *root)
{
 if(root==NULL) return;
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}
void postorder(node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}
void preorder(node *root)
{
    printf("\n%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
int main(){
    root = create();
//    printf("\n");
//    inorder(root);
//    printf("\n");
    postorder(root);
//    printf("\n");
//    preorder(root);

    return 0;
}
