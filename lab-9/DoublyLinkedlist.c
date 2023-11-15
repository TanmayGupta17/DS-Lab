#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *head = NULL;

// insertion in a doubly circular linked list
void insert(int val){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
    if(head == NULL){
        ptr->next = ptr;
        ptr->prev = ptr;
        head = ptr;
        return;
    }
    node *last = head->prev;

    ptr->next = head;
    head->prev = ptr;
    ptr->prev = last;
    last->next = ptr;

}

//deletion in a doubly circular linked list
void delete(){
    node *ptr = (node*)malloc(sizeof(node));
    node *last = head->prev;
    if(head == NULL){
        printf("List is empty");
        return;
    }
    else {
        ptr = last;
        last = last->prev;
        ptr->next = ptr->prev = ptr;
        free(ptr);
        last->next = head;
        head->prev = last;
    }
}

void display(){
    node *temp = head;
    while(temp->next != head){
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}

int main(){
    insert(1);
    insert(2);
    insert(3);
    delete();
    delete();
    display();
}
