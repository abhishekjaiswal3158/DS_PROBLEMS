#include <stdio.h>
int main()
{
    int n;   // Number of elements
    int a[100]; // Array to store elements
    int s;  // Element to search
    int p;  // To store the position of element where the element s found in the array
    n = Read_Number_of_Elements(); // Function reads the number of elements
    Read_Elements_to_Array(a, n);  // Function to read n elements into an array
    s = Read_Element_to_Search();  // Function to read the searching element
    p = Linear_Search(a, n, s);   // Function implements the linear search
    if(p==-1)
       printf("\n Element not found");
    else
       printf("\n Element found at position: %d",p);
    return 0;
}

// Read the number of elements in the Array and return it
int Read_Number_of_Elements()
{
    int a;
    scanf("%d",&a);
    return a;


}

void Read_Elements_to_Array(int *p, int n)    // Read the n elements into array from the keyboard
{
    for(int i=0;i<n;i++){
    	scanf("%d",p);
    	p++;
    }


}
// Read the element you want to search from keyboard and return it
int Read_Element_to_Search()
{
	int n;
    scanf("%d",&n);
    return n;
}

// Write the code for linear search
// On successful search return the index of the searching element
// (if s is at 0'th position return 1)
// for unsuccessful search return -1
int Linear_Search(int *p, int n, int s)  // Write the code for linear search
{
	 int i;
	    for (i = 0; i < n; i++) {
	        if (*p == s){
	            return i+1;
	            break;
	        }
	        p++;
	    }
	    return -1;
	}


