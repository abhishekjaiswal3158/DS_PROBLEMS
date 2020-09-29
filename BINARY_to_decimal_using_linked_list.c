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
 int DECIMAL;
void display(){
    if(head==NULL){
        printf("LIST IS EMPTY");
    }
    else{
        DLL *temp=head;
        printf("BINARY NUMBER OF %d=(",DECIMAL);

        while(temp!=NULL){
            printf("%d ",temp->data);
              
            temp=temp->next;
        }
        printf(")");
    }
}

int main(){
   printf("ENTER THE DECIMAL NUMBER=");
    scanf("%d",&DECIMAL);
    int n=DECIMAL;
    while(n!=0){
        int r=n%2;
       n=n/2;
        insert_in_begining(r);
    }
    display();


}