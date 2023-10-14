#include<stdio.h>
#include<stdlib.h>
#define size 100

int stack[size];
int top = -1;

int pop(){
    int item;
    if(top == -1){
        printf("Stack is empty");
    }
    else {
        item = stack[top];
        top--;
    }
    return item;
}

void push(int item){
    if(top == size - 1){
        printf("Stack is full");
    }
    else {
        stack[++top] = item;
    }
}

int isOperator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            return 1;
        default: 
            return 0;

    }
}

char Operand(char c){
    return ((c>='a' && c<='z') || (c >= 'A' && c<='Z'));
}

int evaluate(char *c){
    int i=0;
    int symbol = c[i];
    int op1,op2,val,result=0;
    while(symbol != '\0'){
        if (symbol>='0' && symbol<='9'){
            int num = symbol - 48;
            push(num);
        }
        else if (Operand(symbol)){
            int num = symbol;
            push(num);
        }
        else if (isOperator(symbol)){
            op2 = pop();
            op1 = pop();
            switch (symbol)
            {
                case '+':
                    result = op1+op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1*op2;
                    break;
                case '/':
                    result = op1/op2;
                    break;
            }
            push(result);
        }
        i++;
        symbol = c[i];
    }
    result = pop();
    return result;
}

int main(){
    char postfix[] = "95+";
    int result = evaluate(postfix);
    printf("%d", result);
}