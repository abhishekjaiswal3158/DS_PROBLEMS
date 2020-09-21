#include <stdio.h>

int main()
{
    int n;   // Number of elements
    int a[100]; // Array to store elements
    int pos; // Position where we want to insert new elements
    int s; // New element to insert
    int i; // indexing purpose
    n = Read_Number_of_Elements(); // Function reads the number of elements
    Read_Elements_to_Array(a, n);  // Function to read n elements into an array
    pos = Read_Pos_to_Insert(); // Read the position where you want to insert an element
    pos = Check_Position(pos, n); //Code to check the pos is valid index or not
    if(pos != -1)
    {
       s = Read_New_Element_to_Insert(); // Read the new element
       Insert_at_Pos(a, &n, pos, s);   // Function to insert a new element s at position pos
       printf("\n");
       for(i=0; i<n; i++)
         printf("%d ",a[i]);
       return 0;
    }
    else printf("Entered wrong position");
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

int Read_Pos_to_Insert() // read and return the position of the new element
{
        int n;
    scanf("%d",&n);
    return n;


}

// Function to verify the new position is a valid index or not
// It is valid if its in between 0 to n
// If it valid return pos
// If it is invalid return -1
int Check_Position(int pos,int n)
{
    if(pos<=n&&pos>=0){
        return pos;
    }
    else{
        return -1;
    }

}

int Read_New_Element_to_Insert() // Read the new element and return
{
    int n;
    scanf("%d",&n);
    return n;

}

void Insert_at_Pos(int *p,int  *n,int pos,int s)   // Function to insert a new element s at position pos
{ // Don't forget to increment n after insertion
    *n=(*n + 1);
   pos--;
    for(int i=*n-1;i>=pos;i--)
    {	
    	p[i]=p[i-1];
    }
    p[pos]=s;
}




