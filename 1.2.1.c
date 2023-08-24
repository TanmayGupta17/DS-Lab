#include<stdio.h>

int main(){
    int n;
    printf("enter no of elements:");
    scanf("%d",&n);
    int a[n];
    printf("enter elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        if (a[i]>a[i+1]){
            int temp = a[i+1];
            a[i+1] = a[i];
            a[i] = temp;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
}