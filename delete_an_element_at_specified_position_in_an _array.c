// Write a program to delete an element in 
#include <stdio.h>

int main()
{
    int n;   // Number of elements
    int a[100]; // Array to store elements
    int pos; // Position where we want to delete new element
    int i; // indexing purpose
    n = Read_Number_of_Elements(); // Function reads the number of elements
    Read_Elements_to_Array(a, n);  // Function to read n elements into an array
    pos = Read_Pos_to_Delete(); // Read the position where you want to insert an element
    pos = Check_Position(a, pos, n); //Code to check the pos is valid index or not
    if(pos != -1)
    {
       Delete_at_Pos(a, &n, pos);   // Function to delete the element at position pos
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

int Read_Pos_to_Delete() // read and return the position of the element to delete
{
          int a;
    scanf("%d",&a);
    return a;


}

// Function to verify the new position is a valid index or not
// It is valid if its in between 0 to n
// If it is valid return pos
// If it is invalid return -1
int Check_Position(int *p, int pos,int n)
{
    if(pos>0&&pos<=n){
    	return pos;
    }else{

    return -1;
}

}
void Delete_at_Pos(int *p,int  *n,int pos)   // Function to delete an at position pos
{ // Don't forget to decrement n after deletion
	pos--;
    for(int i=pos;i<(*n)-1;i++ ){
    	p[i]=p[i+1];
    }
    (*n)=(*n)-1;
    
}


