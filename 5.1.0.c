#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100

int top = -1;
int stack[size];
char postfix[size];
char prefix[size];

void push(char c){
    if(top == size - 1){
        printf("Stack is Full");
    }
    else{
        ++top;
        stack[top] = c;
    }
}

char pop (){
    if(top == -1){
        printf("Stack is Empty");
        return -1;
    }
    else{
        char c = stack[top--];
        return c;
    }
}

int precedance(char infix){
    if ((infix == '*') || (infix == '/')) return 3;
    else if((infix == '+') || (infix == '-')) return 2;
    else return 0;
}

char operand(char infix){
    return ((infix >= 'a' && infix <='z') || (infix >= 'A' && infix <='Z') );
}

int operator(char infix){
    if(infix == '+' || infix == '-' || infix == '*' || infix == '/') return 1;
    else return 0;
}

void  InfixtoPostfix(char infix[]){
    int len = strlen(infix);
    int j = 0;
    int i = 0;
    while(infix[i] != '\0'){
        if(operand(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else {
            if (precedance(infix[i]) > precedance(stack[top])){
                push(infix[i]);
                i++;
            }
            else{
                postfix[j] = pop();
                j++;
            }
        }
    }
    while(top != -1){
        postfix[j] = pop();
        j++;
    }
    printf("%s\n",postfix);
}

int main(){
    char infix[] = "a+b-c";
    InfixtoPostfix(infix);
}