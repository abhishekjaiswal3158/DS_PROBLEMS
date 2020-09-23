
#include<stdio.h>
#include<stdlib.h>
typedef struct Node SLL;
struct Node
{
    int coff;
    int expo;
    SLL *next;
};
SLL *head1=NULL;
SLL *head2=NULL;
SLL *head3=NULL;
SLL *head4=NULL;
SLL *head5=NULL;
int n1;
int n2;

int Read_No_Nodes();
void Traverse_SLL(SLL **);
void Insert_End(SLL **, int,int);
void add();
void subtract();
void  multiply();
void Delete_X(SLL **, int,int);
void remove_duplicate(SLL *);
void  bubbleSort(SLL *);
void swap(SLL *,SLL*);
void reverse(SLL **);


int main()
{
  printf("ENTER THE NUMBER OF TERMS IN THE FIRST POLYNOMIAL=");
    n1 = Read_No_Nodes(); 
     printf("\nENTER THE COFFICIENT AND EXPONENT OF TERMS=\n");
    for(int i=0;i<n1;i++)
    {
      int coff,expo;
      scanf("%d",&coff);
      scanf("%d",&expo);
      Insert_End(&head1, coff,expo);
    }
    remove_duplicate(head1);
    bubbleSort(head1);
    reverse(&head1);
     Traverse_SLL(&head1);
      
      printf("ENTER THE NUMBER OF TERMS IN THE SECOND POLYNOMIAL=");
       n2 = Read_No_Nodes(); 
     printf("\nENTER THE COFFICIENT AND EXPONENT OF TERMS RESPECTIVELY FOR EACH TERM=\n");
    for(int i=0;i<n2;i++)
    {
      int coff,expo;
      scanf("%d",&coff);
      scanf("%d",&expo);
      Insert_End(&head2, coff,expo);
    }
    remove_duplicate(head2);
    bubbleSort(head2);
    reverse(&head2);
     Traverse_SLL(&head2);
     printf("<<<<<<<<<<<<<-----------------------------ADDITION-------------------------------------->>>>>>>>>>>>>>>>>> \n");
      add();
      Traverse_SLL(&head3);
 printf("<<<<<<<<<<<<<-----------------------------SUBTRACTION-------------------------------------->>>>>>>>>>>>>>>>>> \n");
      subtract();
      Traverse_SLL(&head4);
      printf("<<<<<<<<<<<<<-----------------------------MULTIPLICATION-------------------------------------->>>>>>>>>>>>>>>>>> \n");
      multiply();
       Traverse_SLL(&head5);

    return EXIT_SUCCESS;
}


 int Read_No_Nodes()
 { 
     int s;
     scanf("%d",&s);
     return s;


 }


 
void Traverse_SLL(SLL **h)
{
   int i;
   SLL *t;
   if(*h==NULL)
     printf("\nList is empty\n");
   else
   {
       printf("\nThe equation are...\n");
       t = *h;
       while(t!=NULL)
       {
           printf("%dx^%d",t->coff,t->expo);
           if(t->next!=NULL&&t->next->coff>0){
               printf("+");
           }
           
           t = t->next;
       }
       printf("\n");
   }

}

void Insert_End(SLL **h, int c,int e)
{  SLL * newNode=(SLL *)malloc(sizeof(SLL));
   newNode->coff=c;
   newNode->expo=e;
   newNode->next=NULL;
    if(*h==NULL){
       *h=newNode;
    }
    else{
        SLL * temp=*h;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void add() 
{ 
    SLL *temp1=head1;
    SLL *temp2=head2;
while(temp1!=NULL && temp2!=NULL) 
    { 
        int c,e;
        if(temp1->expo > temp2->expo) 
        { 
            e = temp1->expo; 
            c = temp1->coff; 
            temp1 = temp1->next; 
        } 
   
        else if(temp1->expo < temp2->expo) 
        { 
            e = temp2->expo; 
            c = temp2->coff; 
            temp2 = temp2->next; 
        } 
        else
        { 
           e = temp1->expo; 
           c = temp1->coff+temp2->coff; 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
       Insert_End(&head3,c,e);
    } 
while(temp1!=NULL || temp2!=NULL) 
    { 
        int c,e;
        if(temp1!=NULL) 
        { 
            e = temp1->expo; 
            c = temp1->coff; 
            temp1 = temp1->next; 
        } 
        if(temp2!=NULL) 
        { 
            e = temp2->expo; 
            c = temp2->coff; 
            temp2 = temp2->next; 
        } 
       Insert_End(&head3,c,e);
    } 
} 


void subtract() 
{ 
    SLL *temp1=head1;
    SLL *temp2=head2;
while(temp1!=NULL && temp2!=NULL) 
    { 
        
        int c,e;
        if(temp1->expo > temp2->expo) 
        { 
            e = temp1->expo; 
            c = temp1->coff; 
            temp1 = temp1->next; 
        } 
          
        else if(temp1->expo < temp2->expo) 
        { 
            e = (temp2->expo); 
            c = -(temp2->coff); 
            temp2 = temp2->next; 
        } 
          
       
        else
        { 
           e = temp1->expo; 
           c = temp1->coff-temp2->coff; 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
          
      
       Insert_End(&head4,c,e);
    } 
while(temp1!=NULL || temp2!=NULL) 
    { 
        int c,e;
        if(temp1!=NULL) 
        { 
            e = temp1->expo; 
            c = temp1->coff; 
            temp1 = temp1->next; 
        } 
        if(temp2!=NULL) 
        { 
           e = -(temp2->expo); 
            c = -(temp2->coff); 
            temp2 = temp2->next; 
        } 
       Insert_End(&head4,c,e);
    } 
} 



void multiply(){
  SLL *temp1=head1;
  SLL *temp2=head2;
while(temp1!=NULL){
    temp2=head2;
    while (temp2!=NULL)
    {
        int proCoff=temp1->coff*temp2->coff;
        int proexp=temp1->expo+temp2->expo;
        Insert_End(&head5,proCoff,proexp);
        temp2=temp2->next;
    } 
 temp1=temp1->next;
}

remove_duplicate(head5);



}

void Delete_X(SLL **h, int c,int e)
{
	 SLL *curr=*h;
  SLL *prev=NULL;
  if(curr->expo==e && curr->coff==c)
  {
      *h=curr->next;
      return;
  }
  while(curr!=NULL)
  {
     
     
      if(curr->expo==e && curr->coff==c){
       break;}
       
       prev=curr;
       curr=curr->next;
  }
  prev->next=curr->next;
}


void remove_duplicate(SLL *temp3){
while(temp3!=NULL){
    SLL *temp4=temp3->next;
    while(temp4!=NULL){
        if(temp3->expo==temp4->expo){
            temp3->coff=temp3->coff+temp4->coff;
             Delete_X(&temp3, temp4->coff,temp4->expo);
        }
        temp4=temp4->next;
    }
    temp3=temp3->next;
}

}


void bubbleSort(struct Node *start) 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 
  
   
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->expo > ptr1->next->expo) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  

void swap(struct Node *a, struct Node *b) 
{ 
    int c = a->coff;
    int e = a->expo; 
    a->expo=b->expo;
    a->coff=b->coff;
    b->coff=c;
    b->expo=e;
} 

 void reverse(struct Node** head_ref) 
{ 
    struct Node* prev = NULL; 
    struct Node* cur = *head_ref; 
    struct Node* next = NULL; 
    while (cur != NULL) { 
        next = cur->next; 
        cur->next = prev; 
        prev = cur; 
        cur = next; 
    } 
    *head_ref = prev; 
} 
