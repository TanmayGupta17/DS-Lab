#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coeff;
    int pow;
    struct polynomial *next;
}node;

node *sum = NULL;
node *p1 = NULL;
node *p2 = NULL;
node *head = NULL;

void create(int coeff,int pow,node **poly){
    node *temp = (node*)malloc(sizeof(node));
    temp->coeff = coeff;
    temp->pow = pow;
    if (head == NULL){
        head = temp;
        temp->next = NULL;
        return;
    }
    else{
        node *t = head;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = temp;
        temp->next = NULL;
    }
}

void display(){
    node *temp = head;
    while(temp != NULL){
        printf("%dx^%d",temp->coeff,temp->pow);
        if(temp->next != NULL){
            printf("+");
        }
        temp = temp->next;
    }
    printf("\n");
}

void addingPolynomials(node *p1, node *p2, node *sum){
    node *poly1 = p1, *poly2 = p2;
    node *res = sum;
    if (poly1 == NULL){
        sum = poly2;
        return sum;
    }
    else if(poly2 == NULL){
        sum = poly1;
        return sum;
    }
    while(poly1 != NULL && poly2 != NULL){
        if (sum == NULL){
            sum = (node*)malloc(sizeof(node));
            res = sum;
        }
        else{
            res->next = (node*)malloc(sizeof(node));
            res = res->next;
        }
        if(poly1->pow > poly2->pow){
            res->coeff = poly1->coeff;
            res->pow = poly1->pow;
            poly1 = poly1->next;
        }
        else if(poly1->pow < poly2->pow){
            res->coeff = poly2->coeff;
            res->pow = poly2->pow;
            poly2 = poly2->next;
        }
        else if(poly1->pow == poly2->pow){
            res->coeff = poly1->coeff + poly2->coeff;
            res->pow = poly1->pow;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        /*while(poly1 != NULL){
            res->next = (node*)malloc(sizeof(node*));
            res = res->next;
            res->coeff = poly1->coeff;
            res->pow = poly1->pow;
            poly1 = poly1->next;
        }
        while(poly2 != NULL){
            res->next = (node*)malloc(sizeof(node*));
            res = res->next;
            res->coeff = poly2->coeff;
            res->pow = poly2->pow;
            poly2 = poly2->next;
        }*/

    }
    res->next = NULL;
    printf("%dx^%d",res->coeff,res->pow);
}

int main(){
    create(4,2,&p1);
    create(3,1,&p1);
    create(7,0,&p1);
    create(4,2,&p2);
    create(3,1,&p2);
    create(7,0,&p2);
    addingPolynomials(p1,p2,sum);

    display();
    return 0;
}

