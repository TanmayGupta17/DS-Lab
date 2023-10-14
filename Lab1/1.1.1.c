#include<stdio.h>

int main(){
    int n;
    printf("enter no of elements:");
    scanf("%d", &n);
    int a[n] ;
    printf("enter array:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int val;
    printf("enter value:");
    scanf("%d",&val);
    for(int i=0;i<n;i++){
        if (val == a[i]){
            printf("%d", i);
            break;
        }
        
    }
    return 0;
}
