#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    struct node *left;
    struct node *right;
    int data;
}node;

node *root = NULL;

void createTree(){
    int n;
    printf("Enter no of nodes to add in the tree: ");
    scanf("%d",&n);
    int i = 0;
    while(i<n){
        char dir[10];
        int data;
        printf("Enter data: ");
        scanf("%d",&data);
        printf("Enter directions: ");
        scanf("%s",&dir);

        node *curr = root;
        node *prev = curr;

        node *ptr = (node*)malloc(sizeof(node));
        ptr->data = data;
        ptr->left = NULL;
        ptr->right = NULL;

        if(root == NULL){
            root = ptr;
        }
        else{
            int j=0;
            while(dir[j] != '\0'){
                prev = curr;
                if(dir[j] == 'l') curr = curr->left;
                else curr = curr->right;
                j++;
            }
            if(dir[j-1] == 'l') prev->left = ptr;
            else prev->right = ptr;
        }
//        free(ptr);
        i++;
    }

}

void inorder(){
    node *stack[20];
    int top = -1;
    node *temp = root;

    while(1){
        while(temp != NULL){
            stack[++top] = temp;
            temp = temp->left;
        }
        if (top > -1) temp = stack[top--];
        else break;

        printf("%d", temp->data);
        temp = temp->right;
    }

}


int main(){
    createTree();
    inorder();

    return 0;
}
