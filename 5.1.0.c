#include <stdio.h>
#include<string.h>
#define size 100
#include<stdlib.h>

char stack[size];
int top = -1;
int front = 0;
char pop();
void push(char a);
char checkifOperand(char c);
char* convertInfixtoPostfix(char exp[]);
char exp[size];

int main()
{
    printf("enter expression:");
    scanf("%s", &exp);

    char* postfix = convertInfixtoPostfix(exp);
    printf("%s",postfix);

    return 0;
}
int precedence(char ch){
    switch(ch){
    case'+':
    case'-':
        return 1;
    case'*':
    case'/':
        return 2;
    case'^':
        return 3;
    default:
        return -1;
    }
}



char checkifOperand(char c){
    return((c>='a' && c<='z') || (c>='A' && c<='Z') );
}

char* convertInfixtoPostfix(char exp[]){
    int len = strlen(exp);
    char *postfix = (char*)malloc(sizeof(char)*len);
    int j=-1;
    for(int i=0;i<strlen(exp);i++){
        if(checkifOperand(exp[i])){
            postfix[++j] = exp[i];
        }
        else if(exp[i] == '('){
            push('(');
        }
        else if(exp[i] == ')'){
            while(top>-1 && stack[top] == '('){
                    postfix[j++] = stack[top--];
            }
            if(top>-1 && stack[top] != '('){
                printf("Invalid expression");
               }

        }
        else if(precedence(exp[i])){
            while(top>-1 && precedence(stack[top])>= precedence(exp[i])){
                postfix[++j] = stack[top--];
                stack[++top] = exp[i];
            }
        }
        while (top != -1){
            postfix[++j] = pop();
        }

        postfix[++j] = '\0';

    }
        return postfix;

    }





void push(char a){
    if(top == size-1){
        printf("Stack is full");
    }
    else {
        top++;
        stack[top] = a;
    }
}
char pop(){
    if (top == -1){
        printf("stack is empty");
    }
    else {
        char c = stack[top];
        top--;
        return c;
    }
}
