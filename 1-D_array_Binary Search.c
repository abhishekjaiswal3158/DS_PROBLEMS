
#include <stdio.h>

int main()
{
    int n;   // Number of elements
    int a[100]; // Array to store elements
    int s;  // Element to search
    int p;  // To sotre the position of element where the element s found in the array
    int k; // To store the input is in the required form for binary search or not
    n = Read_Number_of_Elements(); // Function reads the number of elements
    Read_Elements_to_Array(a, n);  // Function to read n elements into an array
    k = Verify_Input(a, n); // Function to check the input
    if(k==1)
    {
        s = Read_Element_to_Search();  // Function to read the searching element
        p = Binary_Search(a, 0, n-1, s);   // Function implements the linear search
        if(p==-1)
            printf("\n Element not found");
        else
            printf("\n Element found at position: %d",p);
        return 0;
    }
    else printf("wrong input entered");
    return 0;
}

int Read_Number_of_Elements() // Read the number of elements in the Array and return it
{
     int a;
    scanf("%d",&a);
    return a;


}

void Read_Elements_to_Array(int *p, int n) // Read the n elements into array from the keyboard
{

     for(int i=0;i<n;i++){
    	scanf("%d",p);
    	p++;
    }


}

// Function to check the input is in the required form for binary search or not
// Return 0 if input is not in the proper format
// Return 1 if the input is proper format
int Verify_Input(int a[],int n)
{

  for(int i=0;i<n-1;i++){

      if(a[i]>a[i+1]){
          return 0;
          break;
      }

  }
  return 1;

}

int Read_Element_to_Search() // Read the element you want to search from keyboard and return
{
    int n;
    scanf("%d",&n);
    return n;

}
// Write the code for Binary search
// l is the first element position
// h is the last element position-1
int Binary_Search(int arr[], int l, int h, int s)
{
      if (h >= l) {
        int mid = l + (h - l) / 2;

        if (arr[mid] == s)
            return mid+1;

        
        if (arr[mid] > s)
            return Binary_Search(arr, l, mid - 1, s);

       
        return Binary_Search(arr, mid + 1, h, s);
    }

    
    return -1;
}


