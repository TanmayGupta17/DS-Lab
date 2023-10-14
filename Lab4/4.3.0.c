#include<stdio.h>

int row;
int col;
int sparseLen=0;

typedef struct
{
    int row;
    int col;
    int val;
} sparseSt;

void transpose(int len, sparseSt a[len+1], sparseSt b[len+1])
{
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    int ind = 1;
    int start = 0;

    while(ind<=len)
    {
        for(int i=1;i<=len;i++)
        {
            if(a[i].col == start)
            {
                b[ind].row = a[i].col;
                b[ind].col = a[i].row;
                b[ind].val = a[i].val;
                ind++;
            }
        }
        start++;
    }
}

void disp(int len, sparseSt a[len+1])
{
    for(int i=0;i<=len;i++)
    {
        printf("%d %d %d\n",a[i].row, a[i].col, a[i].val);
    }
}

int main()
{
    printf("Enter row:\n");
    scanf("%d",&row);
    printf("Enter col:\n");
    scanf("%d",&col);

    printf("Enter values:\n");

    int sparseMat[row][col];

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int temp;
            scanf("%d",&temp);
            sparseMat[i][j] = temp;

            if(temp!=0) sparseLen++;
        }
    }

    sparseSt a[sparseLen+1];
    sparseSt b[sparseLen+1];
    a[0].row = row;
    a[0].col = col;
    a[0].val = sparseLen;

    int ind=1;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int temp = sparseMat[i][j];
            if(temp!=0)
            {
                a[ind].row = i;
                a[ind].col = j;
                a[ind].val = temp;
                ind++;
            }
        }
    }

    transpose(sparseLen, a, b);
    printf("Sparse Matrix struct:\n");
    disp(sparseLen, a);
    printf("Sparse Matrix Transpose:\n");
    disp(sparseLen, b);



    return 0;
}

