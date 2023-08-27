//checking for a palindrome string using stacks
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size 100

int stack[size];
int top = -1;
int front = 0;
void push(char a);
void pop();

int main(){
    int i,choice;
    char s[size],b;

    while(1){

        printf("1-enter string\n2-exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){

        case 1:
            printf("Enter string: ");
            scanf("%s",&s);
            for(i=0;s[i]!='/0';i++){
                b=s[i];
                push(b);
            }
            for(i=0;i<(strlen(s)/2);i++){
                if(stack[top]==stack[front]){
                    pop();
                    front++;
                }
                else{
                    printf("%s is not a palindrome",s);
                    break;
                }
            }
            if ((strlen(s)/2)==front){
                printf("%s is a palindrome",s);
            }
            front = 0;
            top = -1;
            break;
        case 2:
            exit(0);
        default:
            printf("Enter a valid choice");


        }
    }
    return 0;

}


void push(char a){
    top++;
    stack[top]=a;
}

void pop(){
    top--;
}
