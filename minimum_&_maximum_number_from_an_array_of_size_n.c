int main()
{
    int n;   // Number of elements
    int a[100]; // Array to store elements
    int b[2]; // To store minimum and maximum elements of the array a[]
    n = Read_Number_of_Elements(); // Function reads the number of elements
    Read_Elements_to_Array(a, n);  // Function to read n elements into an array
    Min_Max_in_Array(a, n, b);   // Function finds the minimuma dn maximum in an array
    printf("\n The minimum element is: %d", b[0]);
    printf("\n The maximum element is: %d", b[1]);
    return 0;
}

int Read_Number_of_Elements() // Read the number of elements in the Array and return it
{
    int n;
    scanf("%d",&n);
    return n;


}

void Read_Elements_to_Array(int *p, int n) // Read the n elements into array from the keyboard
{

     for(int i=0;i<n;i++){
    	scanf("%d",p);
    	p++;
    }

}

// Function to find the minimum and maximum elements of the array a[]
// store minimum element in position b[0]
// store maximum element in position b[0]
// Return 1 if the input is proper format
void Min_Max_in_Array(int a[],int n, int *b)
{
   int i, j;
   for (i = 0; i < n-1; i++)  {
       for (j = 0; j < n-i-1; j++)  {
           if (a[j] > a[j+1]) {
              int temp=a[j];
              a[j]=a[j+1];
               a[j+1]=a[j];
           }
       }
   }
   *b=a[0];
   b++;
   *b=a[n-1];
}



