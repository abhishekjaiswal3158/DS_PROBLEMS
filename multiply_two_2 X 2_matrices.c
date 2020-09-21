// Write a program to multiply two 2*2 matrices.
#include<stdio.h>
int main()
{
    int a[2][2], b[2][2]; // To store matrix elements
    int c[2][2];  // To store the result
    int i,j; // indexing purpose

    Read_Matrix(a,2,2); // Read the first matrix elements
    Read_Matrix(b,2,2); // Read the second matrix elements
    Mult_Matrix(a,b,c,2,2);

    // Display the multiplication result
    printf("\nThe multiplication of matrix a and b is:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Read the elements into a 2 X 2 matrix
void Read_Matrix(int *p, int m, int n)
{
  for(int i=1;i<=m;i++){
     for(int j=1;j<=n;j++){
       scanf("%d", p);
       p++;
     }
 }

}

// Multiply the two matrices p and q and store it in r
void Mult_Matrix(int *p, int *q, int *r, int m, int n)
{
     int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
        	*(r + i * n + j)=0;
            for (k = 0; k < n; k++)
            	*(r + i * n + j) += (*(p + i * n + k))*(*(q + k * n + j));
        }
    }

}

