#include <stdio.h>


int main()
{
   int row,col;
   printf("matrix size(row*col):");
   scanf("%d %d",&row,&col);
   int a[row][col];
   int size=0;
   printf("enter elements:");
   for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d", &a[i][j]);
        }
   }
   for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j] != 0){
                size++;
            }
            else continue;
        }
   }

   int matrix[3][size];
   int k=0;
   for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j] != 0){
                matrix[0][k] = i;
                matrix[1][k] = j;
                matrix[2][k] = a[i][j];
                k++;
            }
            else {
                continue;
            }
        }
   }
   for(int i=0;i<3;i++){
        for(int j=0;j<size;j++){
            printf("%d", matrix[i][j]);
            printf("\t");
        }
        printf("\n");
   }
   return 0;


}
