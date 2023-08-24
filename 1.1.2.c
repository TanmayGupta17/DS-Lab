#include<stdio.h>

int main(){
    int n;
    printf("enter no of elements:");
    scanf("%d",&n);
    int a[n];
    printf("enter array:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int val;
    int start=0;
    int end = n;
    printf("enter value:");
    scanf("%d",&val);
    for(int i=0;i<n/2;i++){
        int mid = (start+end)/2;
        if (val==a[mid]){
            printf("%d\n",a[mid]);
            break;
        }
        else if(a[mid]>val){
            end = mid-1;
        }
        else {
            start = mid + 1;
        }
    }

    return 0;
}