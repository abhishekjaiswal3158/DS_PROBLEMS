#include<stdio.h>
int main()
{
    int a[20][20], b[20][20]; // To store matrix elements
    int c[20][20];  // To store the result
    int m,n,p,q,i,j; // indexing purpose

    Read_Sizeof_Matrix(&m, &n);
    Read_Sizeof_Matrix(&p, &q);
    if(Check_Matrix_Multiplication(m,n,p,q))
    {
      Read_Matrix(a,m,n); // Read the first matrix elements
      Read_Matrix(b,p,q); // Read the second matrix elements
      Mult_Matrix(a,b,c,m,n,p,q);

      // Display the multiplication result
      printf("\nThe multiplication of matrix a and b is:\n");
      for(i=0;i<m;i++)
      {
        for(j=0;j<q;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
       }
      }
     else
      printf("Matrix multiplication Not Possible");
    return 0;
}

// Read the elements into a m X n matrix
void Read_Matrix(int p[20][20], int m, int n)
{      int i,j;
    for( i=0;i<m;i++){
        for( j=0;j<n;j++){
           scanf("%d",&p[i][j]);
        }
    }

}

// Multiply the two matrices p and q and store it in r
void Mult_Matrix(int a[20][20], int b[20][20], int c[20][20], int m, int n, int p, int q)
{
      int k, i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
        {
            c[i][j]=0;
            for (k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

}

// Read the size of matrix
void Read_Sizeof_Matrix(int *m, int *n)
{
    scanf("%d",m);
    scanf("%d",n);
}

// Verify matrix multiplication is possible or not
// if possible return 1 otherwise retuen 0
int Check_Matrix_Multiplication(int m,int n,int p,int q)
{

    if(n==p){
        return 1;
    }
    else{
        return 0;
    }


}

