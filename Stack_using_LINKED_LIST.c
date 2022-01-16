#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*create(int key){
    struct node*new= (struct node*)malloc(sizeof(struct node));
    new->data=key;
    new->next=NULL;
}
struct node*push(struct node*head_ref,int value){
    struct node*new_node=create(value);
    if(head_ref==NULL){
        head_ref=new_node;
        return head_ref;
    }
    new_node->next=head_ref;
    head_ref=new_node;
    return head_ref;
}
struct node*pop(struct node*head_ref){
    if(head_ref==NULL){
    printf("STACk underflow\n");
    return head_ref;
    }
    struct node*p=head_ref;
    head_ref=head_ref->next;
    printf("%d is popped out from Stack\n",p->data);
    free(p);
    return head_ref;
}
void print_stack(struct node*ref){
    while(ref!=NULL){
        printf("%d\t",ref->data);
        ref=ref->next;
    }
    printf("\n");
}
int main(){
    struct node*head=NULL;
    int temp;
    int choice;
        printf("1. For Pushing element in Stack\n2. For popping out element from STACK\n3. For printing the STAck\n-1. For exiting the program\n");
    while(choice!=-1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    printf("Enter the value you want to enter in the STACK: ");
    scanf("%d",&temp);
        head=push(head,temp);
        break;
    case 2:
    head=pop(head);
    break;
    case 3:
    print_stack(head);
    break;
    case-1:
    exit(0);
    default:
        printf("Enter valid choice GENTLEMAN\n");
        break;
    }
    }
}