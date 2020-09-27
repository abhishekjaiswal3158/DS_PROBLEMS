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
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->prev=temp;

    }
}

void  insert_in_begining( int data){
     DLL * new_node=(DLL *)malloc(sizeof(DLL));
     new_node->data=data;
     new_node->next=new_node->prev=NULL;
     DLL *temp=head;
    if(head==NULL){
        head=new_node;
    }
    else{
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
    }
}

int check_node_exist(int data){
int notify=0;
if(head==NULL){
    return notify;
}
else
{
    DLL*temp=head;
    while(temp!=NULL){
     if(temp->data==data ){
         notify=1;
         return notify;
        
     }
      temp=temp->next;
    }
}

}

void  insert_after_specific_node(int data,int data_before){
     DLL * new_node=(DLL *)malloc(sizeof(DLL));
    new_node->data=data;
    new_node->next=new_node->prev=NULL;
    DLL *temp=head;
    while(temp!=NULL){
        if(temp->data==data_before){
            break;
        }
        temp=temp->next;
    }
    new_node->prev=temp;
    new_node->next=temp->next;
    if(new_node->next!=NULL){
        new_node->next->prev=new_node;
    }
    temp->next=new_node;
    
}

void  insert_before_specific_node(int data,int data2){
    DLL * new_node=(DLL *)malloc(sizeof(DLL));
    new_node->data=data;
    new_node->next=new_node->prev=NULL;
    DLL *temp=head;
    if(temp->data==data2){
     new_node->next=temp;
     temp->prev=new_node;
     head=new_node;
    }
    else{
        while (temp!=NULL){
        if(temp->data==data2){
            break;
        }
        temp=temp->next;
        }
        new_node->next=temp;
        new_node->prev=temp->prev;
        temp->prev->next=new_node;
        temp->prev=new_node;
    }

}

void delete_first_node(){
    if(head==NULL){
        printf("DELETION IS NOT POSSIBLE");
    }
   
    else if(head->next==NULL){
        DLL *temp=head;
        head=NULL;
        free(temp);
    }
   else if(head->next!=NULL){
       DLL * temp=head;
       head=head->next;
       head->prev=NULL;
    free(temp);}
}

void delete_last_node(){
     if(head==NULL){
        printf("DELETION IS NOT POSSIBLE");
    }
    else if(head->next==NULL){
       DLL *temp=head;
       head=NULL;
       free(temp);
    }
    else{
    DLL *temp=head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    }
}

void delete_specific_node( int DELETE){
     if(head==NULL){
        printf("DELETION IS NOT POSSIBLE");
    }
   else if(head->data==DELETE){
       DLL *temp=head;
       if(head->next!=NULL){
       head=head->next;
       head->prev=NULL;
       }
       else{
           head=NULL;
       }
       free(temp);
    }
    else{
        DLL*temp=head;
        while(temp!=NULL){
            if(temp->data==DELETE){
                break;
            }
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
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
        while(temp!=NULL){
            printf("%d,",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    printf("<<<<<<------WELCOME TO MY DOUBLY_ LINKED_LIST---->>>>>\n");
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
     printf("\nTHIS NUMBER DOES NOT EXIST\n");
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
       printf("\nTHIS NUMBER DOES NOT EXIST\n");
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