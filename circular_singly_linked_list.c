#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

typedef struct Node CSL;

struct Node
{
    int data;
    CSL *next;
}*head = NULL;


void insertion_in_end(int data){
   CSL * new_node=(CSL*)malloc(sizeof(CSL));
    new_node->data=data;
    new_node->next==NULL;
    CSL *temp=head;
    if(head==NULL){
        head=new_node;
        head->next=head;
    }
    else{
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=head;

    }
}

void  insert_in_begining( int data){
    CSL * new_node=(CSL *)malloc(sizeof(CSL));
     new_node->data=data;
     new_node->next=NULL;
     CSL *temp=head;
    if(head==NULL){
        head=new_node;
        head->next=head;
    }
    else{
         while(temp->next!=head){
            temp=temp->next;
        }
        new_node->next=head;
        head=new_node;
        temp->next=head;

    }
}

int check_node_exist(int data){
   if(head==NULL){
       return 0;
   }
   else{
       CSL * temp=head;
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

void  insert_after_specific_node(int data,int data_before){
     CSL * new_node=(CSL *)malloc(sizeof(CSL));
    new_node->data=data;
    new_node->next=NULL;
    CSL *temp=head;
    do{
        if(temp->data==data_before){
            break;
        }
        temp=temp->next;
    }while (temp!=head);
    new_node->next=temp->next;
    temp->next=new_node;
    
}


void  insert_before_specific_node(int data,int data2){
    CSL * new_node=(CSL *)malloc(sizeof(CSL));
    new_node->data=data;
    new_node->next=NULL;
    CSL *temp=head;
    if(temp->data==data2){
     while(temp->next!=head){
      temp=temp->next;
     }
     new_node->next=head;
     head=new_node;
     temp->next=head;
    }
    else{
         CSL *prev=head;
        do{
        if(temp->data==data2){
            break;
        }
        prev=temp;
        temp=temp->next;
        }while (temp!=head);
        new_node->next=temp;
       prev->next=new_node;
      
    }

}



void delete_first_node(){
    if(head==NULL){
        printf("DELETION IS NOT POSSIBLE");
    }
   
    else if(head->next==head){
       CSL *temp=head;
        head=NULL;
        free(temp);
    }
   else if(head->next!=NULL){
       CSL * temp=head;
        while(temp->next!=head){
      temp=temp->next;
     }
     CSL * temp1=head;
       head=head->next;
      temp->next=head;
    free(temp1);
    }
}

void delete_last_node(){
     if(head==NULL){
        printf("DELETION IS NOT POSSIBLE");
    }
    else if(head->next==head){
       CSL *temp=head;
       head=NULL;
       free(temp);
    }
    else{
    CSL *temp=head;
    CSL*prev=head;
    while(temp->next!=head){
        prev=temp;
      temp=temp->next;
     }
    prev->next=temp->next;
    free(temp);
    }
}

void delete_specific_node( int key){
    if (head == NULL) 
        return; 
  
    CSL *curr = head, *prev; 
    while (curr->data != key) { 
        if (curr->next == head) { 
            break; 
        } 
  
        prev = curr; 
        curr = curr->next; 
    }  
    if (curr->next == curr) { 
        head = NULL; 
        free(curr); 
        return; 
    } 
    if (curr == head) { 
        prev = head; 
        while (prev->next != head) 
            prev = prev->next; 
        head = curr->next; 
        prev->next = head; 
        free(curr); 
    } 
    else if (curr->next == head&&curr->next!=curr) { 
        prev->next = head; 
        free(curr); 
    } 
    else { 
        prev->next = curr->next; 
        free(curr); 
    } 
}

void display(){
    if(head==NULL){
        printf("LIST IS EMPTY");
    }
    else{
        CSL *temp=head;
        printf("NUMBER IN THE LIST ARE=");
         do {
            printf("%d",temp->data);
            temp = temp->next;
            if(temp!=head){
                printf(",");
            }
        }while(temp!=head);
    }
}

int main(){
    printf("<<<<<<------WELCOME TO MY CYCLIC_SINGLY_LINKED_LIST---->>>>>\n");
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
 printf("\nENTER THE DATA AFTER WHICH U WANT TO INSERT=");
int data1;
 scanf("%d",&data1);
 int check=check_node_exist(data1);
 if(check==0){
     printf("THIS NUMBER DOES NOT EXIST\n");
 }
 else{
     int data;
     printf("ENTER THE NUMBER THAT U WANT TO INSERT=");
     scanf("%d",&data);
     insert_after_specific_node(data,data1);
 }
  display();
   printf("\nENTER THE DATA BEFORE WHICH U WANT TO INSERT=");
   int data2;
   scanf("%d",&data2);
   int check1=check_node_exist(data2);
   if(check1==0){
       printf("THIS NUMBER DOES NOT EXIST\n");
   }
   else{
        int data;
     printf("ENTER THE NUMBER THAT U WANT TO INSERT=");
     scanf("%d",&data);
     insert_before_specific_node(data,data2);
   }
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
   printf("\nENETER THE NUMBER WHICH U WANT TO DELETE\n");
 int DELETE;
scanf("%d",&DELETE);
int check3=check_node_exist(DELETE);
if(check3!=1){
printf("NUMBER DOES NOT EXIST\n");
}
else{
    
    delete_specific_node(DELETE);
}
display();
}