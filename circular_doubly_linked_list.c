#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

typedef struct Node DLL;

struct Node
{
    int data;
    DLL *next;
    DLL *prev;
}*head = NULL;

void insertion_in_end(int data){
    DLL * new_node=(DLL *)malloc(sizeof(DLL));
    new_node->data=data;
    new_node->next=new_node->prev=NULL;
    DLL *temp=head;
    if(head==NULL){
        head=new_node;
        new_node->next=new_node;
        new_node->prev=new_node;
    }
    else{
       new_node->next=head;
       new_node->prev=head->prev;
       head->prev->next=new_node;
       head->prev=new_node;

    }
}

void  insert_in_begining( int data){
     DLL * new_node=(DLL *)malloc(sizeof(DLL));
     new_node->data=data;
     new_node->next=new_node->prev=NULL;
     DLL *temp=head;
     if(head==NULL){
        head=new_node;
        new_node->next=new_node;
        new_node->prev=new_node;
     }
     else{
       new_node->next=head;
       new_node->prev=head->prev;
       head->prev->next=new_node;
       head=new_node;
     }
}

int check_node_exist(int data){
   if(head==NULL){
       return 0;
   }
   else{
     DLL *temp=head;
       do{
           if(temp->data==data){
               return 1;
               break;
           }
           temp=temp->next;
       }
       while(temp!=head);
       return 0;
   }
}



void delete_first_node()  
{  
    DLL *temp;  
    if(head == NULL)  
    {  
        printf("\nNUMBER DOES NOT EXIST\n");  
    }  
    else if(head->next == head)  
    {  
        head = NULL;   
        free(head);  
    }  
    else  
    {  
        temp = head;   
        while(temp -> next != head)  
        {  
            temp = temp -> next;  
        }  
        temp -> next = head -> next;  
        head -> next -> prev = temp;  
        free(head);  
        head = temp -> next;   
    }  
}

void delete_last_node()  
{  
     if(head==NULL){
        printf("DELETION IS NOT POSSIBLE");
    }
    else if(head->next==head){
       DLL *temp=head;
       head=NULL;
       free(temp);
    }
    else{
    DLL *temp=head;
    while(temp->next!=head){
        temp= temp->next;
    }
    head->prev=temp->prev;
   temp->prev->next=head;
    free(temp);
    }
}  



void display(){
    if(head==NULL){
        printf("LIST IS EMPTY");
    }
    else{
        DLL *temp=head;
        printf("NUMBER IN THE LIST ARE=");
        do
        {
            printf("%d",temp->data);
            
            if(temp->next!=head){
                printf(",");
            }
            temp=temp->next;
        } while (temp!=head);
        
    }
}

int main(){
    printf("<<<<<<------WELCOME TO MY CIRCULAR_DOUBLY_ LINKED_LIST---->>>>>\n");
    printf("ENTER THE NUMBER OF NODE THAT U WANT TO INSERT=");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        insertion_in_end(data);
     }
    display();
     printf("\nENTER THE NUMBER THAT U WANT TO INSERT IN THE BEGINNING=");
     int data_in_begining;
     scanf("%d",& data_in_begining);
     insert_in_begining( data_in_begining);
     display();
     printf("\nENTER THE NUMBER THAT U WANT TO INSERT IN THE END=");
int data_in_end;
 scanf("%d",& data_in_end);
 insertion_in_end( data_in_end);
 display();

  printf("\nIF YOU WANT TO DELETE FIRST NODE THAN ENTER 1\n");
   int del1;
   printf("ENTER number=");
   scanf("%d",&del1);
   if(del1==1){
       delete_first_node();
         printf("FIRST NODE IS DELETED\n");
   }
   else{
       printf("FIRST NODE IS NOT DELETED\n");
   }
   display();
   printf("\nIF YOU WANT TO DELETE LAST NODE THAN ENTER 1\n");
   int del2;
   printf("ENTER NUMBER=");
   scanf("%d",&del2);
   if(del2==1){
       delete_last_node();
         printf("LAST NODE IS DELETED\n");
   }
   else{
       printf("LAST NODE IS NOT DELETED\n");
   }
   display();

}