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
void Insert_Begin(SLL *, int);
int Read_Element_to_Insert();
int Read_X();
int Search_X(SLL *, int);
void Insert_After_X(SLL *, int, int);
void Delete_Begin(SLL *);
void Delete_Last(SLL *);
void Delete_X(SLL *, int);

int main()
{
    int n, i, j, s, x, p;
    n = Read_No_Nodes(); // Read the number of nodes to be created;
    //Use insert_Last and create a list with n nodes
    for(i=0;i<n;i++)
    {
       s = Read_Element_to_Insert();
       Insert_End(head, s);
    }
    Traverse_SLL(head);

    //Insert an element at begining
    s = Read_Element_to_Insert();
    Insert_Begin(head, s);
    Traverse_SLL(head);

    // Insert an element at end
    s = Read_Element_to_Insert();
    Insert_End(head, s);
    Traverse_SLL(head);

    // Insert an element after x
    x = Read_X();
    p = Search_X(head, x);
	
    if(p == x)
    {
      s = Read_Element_to_Insert();
      Insert_After_X(head, s, x);
      Traverse_SLL(head);
    }
    else
    printf("\nNo element %d\n",x);
    // Delete the first node
    Delete_Begin(head);
    Traverse_SLL(head);

    // Delete the last node
    Delete_Last(head);
    Traverse_SLL(head);

    // Delete node X
    x = Read_X();
    p = Search_X(head, x);
	
    if(p == x)
    {
       Delete_X(head, x);
       Traverse_SLL(head);
    }
    else
      printf("\nNo element %d\n",x);


    return EXIT_SUCCESS;
}

// Read the number of nodes to be created and return
 int Read_No_Nodes()
 { 
     int s;
     scanf("%d",&s);
     return s;


 }


 // Dsiplay the elements in the list
void Traverse_SLL(SLL *h)
{
   int i;
   SLL *t;
   if(h==NULL)
     printf("\nList is empty\n");
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
{  SLL * newNode=(SLL *)malloc(sizeof(SLL));
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

// Create a new node and insert at the begining of the list
void Insert_Begin(SLL *h, int s)
{
	 SLL * newNode=(SLL *)malloc(sizeof(SLL));
	   newNode->data=s;
	   newNode->next=NULL;
	    if(head==NULL){
	        head=newNode;
	    }
	    else{
	        SLL * temp=head;
	        head=newNode;
	        newNode->next=temp;
	    }
}

// Read an integer element and return
int Read_X()
{
	    int n;
	    scanf("%d",&n);
	    return n;

}

// Create a new node and load s in new node and insertit after a node which contains x
void Insert_After_X(SLL *h, int s, int x)
{
	 SLL * newNode=(SLL *)malloc(sizeof(SLL));
		   newNode->data=s;
		   newNode->next=NULL;
		    if(head==NULL){
		      printf("LIST IS EMPTY");
		    }
		    else{
				
				int count1=0;
		SLL *temp1=head;
		while(temp1!=NULL){
			temp1=temp1->next;
			count1++;
		}
		    	SLL * temp=head;
		    	int count=0;
		    	while (temp!=NULL){
		    		if(temp->data==x){
		    			break;
		    		}
		    		else{
		    			count++;
		    		}
		    		temp=temp->next;
		    	}
		    	if(count==count1){
		    		printf("%d does not exist",x);
		    	}
		    	else{
		    	SLL * temp1=temp->next;
		    	temp->next=newNode;
		    	newNode->next=temp1;
		    	}
		    }
}

// Delete the first node
void Delete_Begin(SLL *h)
{
	if(head==NULL){
			      printf("LIST IS EMPTY");
    }
	else{
		SLL * temp=head;
		head=head->next;
		free(temp);
	}

}


// Delete the Last node
void Delete_Last(SLL *h)
{
	 if(head==NULL){
		  printf("LIST IS EMPTY");
	  }

	 else{
	        SLL * temp=head;
	        SLL *prev;
           if(temp->next==NULL)
          {
              head=NULL;
               return;
          }
           else{
	        while(temp->next!=NULL){
	        	prev=temp;
	            temp=temp->next;
	        }
	        prev->next=NULL;
	        free(temp);
}
	    }
}


// Delete the node whcih contains data elelemtn x
void Delete_X(SLL *h, int x)
{
	 SLL *curr=head;
  SLL *prev=NULL;
  if(curr->data==x)
  {
      head=curr->next;
      return;
  }
  while(curr!=NULL)
  {
     
     
      if(curr->data==x){
       break;}
       
       prev=curr;
       curr=curr->next;
  }
  prev->next=curr->next;
  head=h;

}

// Check x is there in the list or not
// if x is in the list return x otherwise return 0
int Search_X(SLL *h, int x)
{
	if(head==NULL){
		return 0;
	}
		else{
		int count=0;
		SLL *temp=head;
		while(temp!=NULL){
			temp=temp->next;
			count++;
		}
		int count1=0;
		SLL *temp1=head;
		while(temp1!=NULL){
			if(temp1->data==x){
				break;
			}
			else{
				temp1=temp1->next;
				count1++;
			}
			
		}
		if(count==count1){
			return 0;
		}
		else{
			return x;
		}
				
		}

}


