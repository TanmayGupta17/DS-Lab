#include <stdio.h>

int main() {
    int m, n, i, j;
    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &m, &n);

    int A[m][n], B[m][n], C[m][n];

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &m, &n);

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = (A[i][j] > B[i][j])? A[i][j] : B[i][j];
        }
    }

    printf("The resulting matrix C is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}