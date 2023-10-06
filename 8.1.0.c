#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

node *head = NULL;
//TRAVERSING THE LINKED LIST (PART7)
void display(){
    node *ptr;
    for(ptr = head;ptr != NULL;ptr = ptr->next){
        printf("%d\n",ptr->data);
    }
}

void InsertAtBeginning(int val){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
    if (head == NULL){
        head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
    }
    else {
        ptr->next = head;
        ptr->prev = NULL;
        head->prev = ptr;
        head = ptr;
    }
}
//INSERTING AT THE REAR END (PART1)
void insertAtEnd(int val){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
    if(head == NULL){
        head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
        return;
    }
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
        ptr->next = NULL;
        temp->next = ptr;
        ptr->prev = temp;
}
//INSERT AT SPECIFIC POSITION (PART3)
void InsertAtPos(int pos,int val){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
    if(head == NULL){
        head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
        return;
    }
    int i=0;
    node *temp = head;
    while (i<pos-1){
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next = ptr;

}
//INSERTING AFTER A PARTICULAR ELEMENT (PART5)
void InsertAfterElement(int ele,int val){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
    if(head == NULL){
        printf("NO Element present");
        head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
        return;
    }
    node *temp = head;
    while(temp->data != ele){
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    ptr->prev = temp;
}
//INSERTING BEFORE A PARTICULAR ELEMENT (PART6)
void InsertBeforeElement(int ele,int val){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = val;
     if(head == NULL){
        head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
        return;
    }
    node *temp = head;
    while(temp->next->data != ele){
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    ptr->prev = temp;
}
//DELETION AT THE END (PART2)
void deleteAtEnd(){
    node *temp = head;
    node *ptr = head->next;
     if(head == NULL){
       free(head);
    }
    while(ptr->next != NULL){
        ptr = ptr->next;
        temp = temp->next;
    }
    free(ptr);
    temp->next = NULL;

}
//DELETION AT A SPECIFIC POSITION (PART4)
void deleteAtPos(int pos){
    node *ptr = head;
    node *temp = head->next;
    int i=0;
    while(i!=pos-1){
        ptr = ptr->next;
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);

}

node revlist(){
    node *previousNode = NULL;
    node *current = head;
    while(current != NULL){
        previousNode = current->prev;
      current->prev = current->next;
      current->next = previousNode;
      current = current->prev;

    }
    head = previousNode;
}

int main(){
    InsertAtBeginning(10);
    insertAtEnd(20);
    InsertAtPos(1,25);
    InsertAfterElement(25,30);
    InsertBeforeElement(30,40);
    deleteAtEnd();
    deleteAtPos(1);
    revlist();
    display();
    return 0;
}
