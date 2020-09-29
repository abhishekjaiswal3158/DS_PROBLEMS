#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

typedef struct Node CSL;

struct Node
{
    int data;
    CSL *next;
}*head1 = NULL;

CSL *head2=NULL;
CSL *head3=NULL;

void insertion_in_end(int data,CSL **head){
   CSL * new_node=(CSL*)malloc(sizeof(CSL));
    new_node->data=data;
    new_node->next=NULL;
    if(*head==NULL){
       *head=new_node;
       (*head)->next=*head;
    }
    else{
         CSL *temp=(*head);
        while((temp)->next!=(*head)){
            temp=(temp)->next;
        }
        (temp)->next=new_node;
        new_node->next=(*head);

    }
}




void display(CSL *head){
    if(head==NULL){
        printf("LIST IS EMPTY");
    }
    else{
        CSL *temp=head;
         do {
            printf("%d",temp->data);
            temp = temp->next;
            if(temp!=head){
                printf(",");
            }
        }while(temp!=head);
        printf("\n");
    }
}

int main(){
     printf("<<<<<<------MERGING OF CSL---->>>>>\n");
     start1:
    printf("ENTER THE NUMBER OF NODE THAT U WANT TO INSERT IN FIRST CSLL=");
    int n;
    
    scanf("%d",&n);
    int pre=0;
    int data=0;
    for(int i=0;i<n;i++){
        pre=data;
        printf("ENTER DATA=");
        scanf("%d",&data);
         if(pre>data&&i!=0){
             head1=NULL;
             printf("\n!!!!!!!THE LIST MUST BE IN ASCENIDNG ORDER!!!!!!! \n<<<PLEASE RE_ENTER THE LIST>>>\n");
             goto start1;
         }
         
       insertion_in_end(data,&head1);
    }
     printf("ELEMENT IN FIRST CSLL=");
    display(head1);
start2:
      printf("ENTER THE NUMBER OF NODE THAT U WANT TO INSERT IN SECOND CSLL=");
    int n1;
    scanf("%d",&n1);
    int pre1=0;
    int data1=0;
    for(int i=0;i<n1;i++){
        pre1=data1;
        printf("ENTER DATA=");
        scanf("%d",&data1);
         if(pre1>data1&&i!=0){
             head2=NULL;
             printf("\n!!!!!!!THE LIST MUST BE IN ASCENIDNG ORDER!!!!!!!\n <<<PLEASE RE_ENTER THE LIST>>>\n");
             goto start2;
         }
         
       insertion_in_end(data1,&head2);
    }
     printf("ELEMENT IN SECOND CSLL=");
    display(head2);
int count1=0;
int count2=0;
CSL *temp1=head1;
CSL *temp2=head2;

while(1){
    if(temp1->data>temp2->data){
        insertion_in_end(temp2->data,&head3);
         count2++;
        if(temp2->next==head2){
           temp2=temp2->next;
            break;
        }
        temp2=temp2->next;
       
    }
     else {
        insertion_in_end(temp1->data,&head3);
       count1++;
        if(temp1->next==head1){
           temp1=temp1->next;
            break;
        }
        temp1=temp1->next;
        
    }

}
while(temp1!=head1||count1==0){
 insertion_in_end(temp1->data,&head3);
 temp1=temp1->next;
count1++;
}
while(temp2!=head2||count2==0){
 insertion_in_end(temp2->data,&head3);
 temp2=temp2->next;
  count2++;
}
printf("ELEMENT OF CSLL AFTER MERGING BOTH CSLL=");
display(head3);
}