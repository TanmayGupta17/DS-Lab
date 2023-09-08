#include <stdio.h>
#include <stdlib.h>
#include<String.h>

#define size 100

int top = -1;
int infix[size];
char stack[size];
void push(char c);
void pop();
int infixtoprefix();
int reverse(char c);
char exp[size];


int main()
{
    printf("enter infix:");
    scanf("%s", &exp);

    printf("%s", infixtoprefix)

   return 0;
}
void brackets (char *exp)
{
  int i = 0;
  while (exp[i] != '\0')
    {
      if (exp[i] == '(')
	exp[i] = ')';
      else if (exp[i] == ')')
	exp[i] = '(';
      i++;
    }
}

int precedence(char c){
    switch(c){
        case'+':
        case'-':
            return 1;
        case'*':
        case'/':
            return 2;
        case'^':
            return 3;
    }
        return -1;
}

char operand(char c){
    return (c >'a' && c<'z' || c>'A' && c<'Z');
}

char reverse(char exp[]){
    int len = strlen(exp);
    int j = len;int i=0;
    char temp[size];
    temp[j--] = '/0';
    while(exp[i] != '/0'){
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);


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
char infixtoprefix(){
    reverse(exp);
    bracket(exp);
    convertInfixtoPostfix(exp);
    reverse(convertInfixtoPostfix);
}


void push(char c){
    if(top == size-1){
        printf("stack is full");
    }
    else {
        stack[top++] = c;
    }
}

void pop(){
    if(top == -1){
        printf("Stack is empty");
    }
    else {
        return stack[top--];
    }
}
