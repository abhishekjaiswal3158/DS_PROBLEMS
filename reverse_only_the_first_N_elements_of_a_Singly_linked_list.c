// Reverse the first n nodes in the list, 
//means the n th node should be the first node
// First node should be the nth node
// Dont change the data in the nodes, only move the nodes to respective positions

#include<stdio.h>
#include<stdlib.h>
typedef struct Node SLL;
struct Node
{
    int data;
    SLL *next;
}*head = NULL;

int Read_No_Nodes();
void Traverse_SLL(SLL *);
void Insert_End(SLL *, int); 
void Reverse(SLL *, int);
int Read_Element_to_Insert();

int main()
{
    int n, i, j, s, x, m;
    n = Read_No_Nodes(); // Read the number of nodes to be created;
    //Use insert_Last and create a list with n nodes
    for(i=0;i<n;i++)
    {
       s = Read_Element_to_Insert();
       Insert_End(head, s);    
    }
    Traverse_SLL(head);
    
    // Read number of nodes to be reversed
    m = Read_No_Nodes();
    if(m<=n && n>0)
      {
           Reverse(head, m);
           Traverse_SLL(head);
      }
      else
        printf("\n Reverse is not possible");
    return 0;
}


// Read the number of nodes to be created and return
 int Read_No_Nodes()
 {
     
   int n;
   scanf("%d",&n);
   return n;
     
 }
 
 
 // Dsiplay the elements in the list
void Traverse_SLL(SLL *h)
{
   int i;
   SLL *t; 
   if(h==NULL)
     printf("\nList is empty");
   else
   {
       printf("\nThe elements in list are...\n");
       t = h;
       while(t!=NULL)
       {
           printf("%d\n",t->data);
           t = t->next;
       }
   }
    
}
// Read an integer element and return
int Read_Element_to_Insert()
{
      
   int n;
   scanf("%d",&n);
   return n;
}

// Create a new node and insert it at the end of the list
void Insert_End(SLL *h, int s)
{
     SLL * newNode=(SLL *)malloc(sizeof(SLL));
   newNode->data=s;
   newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        SLL * temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    
    
}

// Reverse the first m nodes
void Reverse(SLL *h, int m)
{      SLL *newhead=head;
	SLL *temp=head->next;
	head->next=NULL;
int count=1;
	while(count<m){
		SLL *n=newhead;
		newhead=temp;
		temp=temp->next;
		newhead->next=n;
               count++;
	}
head->next=temp;
        head=newhead;
        
	
}



