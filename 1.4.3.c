#include<stdio.h>
int multiply(int a, int b){
    if (b ==0){
        return 0;
    }
    else {
        return a + multiply(a,b-1);
    }
}
int main(){
    int a,b;
    printf("enter two nos.:");
    scanf("%d%d",&a,&b);
    multiply (a,b);
    printf("%d",multiply(a,b));
}