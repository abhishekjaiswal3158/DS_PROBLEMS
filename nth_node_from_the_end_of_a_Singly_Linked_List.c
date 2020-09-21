// Find the nth node from the end of the list
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
SLL* Find_N_th_NODE(SLL *, int);
int Read_Element_to_Insert();
int Read_Node();

int main()
{
    int n, i, m, s;
    SLL *t;
    n = Read_No_Nodes(); // Read the number of nodes to be created;
    //Use insert_Last and create a list with n nodes
    for(i=0;i<n;i++)
    {
       s = Read_Element_to_Insert();
       Insert_End(head, s);    
    }
    Traverse_SLL(head);
    m = Read_Node(); // Read the which node from the end you require
   if(m<=n && n>0)
   {
        t = Find_N_th_NODE(head, m);
        printf("\n The data in nth node is %d", t->data);
     }
   else
     printf("\n There is no nth node");
return 0;
}


// Read the number of nodes to be created and return
 int Read_No_Nodes()
 {
      int n;
    scanf("%d",&n);
    return n;
   
     
 }
 
 
 // Display the elements in the list
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

// Return the address of nth node from the end of the list
SLL* Find_N_th_NODE(SLL *h, int n)
{int count=0;
    SLL *temp=head;
    while(temp!=NULL){
     temp=temp->next;  
     count++;
    }

    int num=count-n+1;

    SLL *node=head;
    for(int i=1;i<num;i++){
        node=node->next;
    }

    return node;
}


int Read_Node() // Read the which node from the end you require
{
     int n;
    scanf("%d",&n);
    return n;
    
}


