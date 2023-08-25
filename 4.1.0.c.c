#include <stdio.h>
#include <stdlib.h>
#define size 10
int front,rear;
int q[size];
void delete();
void insert(int item);
void display();
int main(){

    int front = 0;
    int rear = -1;

    int choice,item;

    while(1){
        int choice;
        printf("enter your choice:\n");
        printf("1-insert element\n2-delete element\n3-diplay queue\n4-exit\n");
        scanf("%d",&choice);

        switch(choice){
        case 1:
            printf("enter element to insert:");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            delete();
            if(front != rear){
                printf("deleted item %d",q[front]);
            }
            else if (front == rear){
                printf("queue is empty");
            }
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program");
            return 0;
        }
    }




}

void delete(){
    if(front>rear){
        return -1;
    }
    int deleteditem = q[front];
    front=(front+1)%size;
    return deleteditem;
}

void insert(int item){
    if(rear == size-1){
        printf("queue will overflow");
        return;
    }
    rear=(rear+1)%size;
    q[rear] = item;
}

void display(){
    int i;
    for(i = (front+1)%size;i!=rear;i=(i+1)%size){
        printf("%d\n",q[i]);
    }
    printf("%d\n",q[i]);
}
