#include<stdio.h>                   //Singhal SAab
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;
};
struct node*create(){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    return new;
}
struct node*addbeg(struct node*head_ref,int value){
    struct node*ptr=create();
        if(head_ref==NULL){
            ptr->data=value;
            ptr->prev=NULL;
            ptr->next=NULL;
            return ptr;
    }
    ptr->data=value;
    ptr->next=head_ref;
    ptr->prev=NULL;
    head_ref->prev=ptr;
    head_ref=ptr;
    return head_ref;
}
struct node*addend(struct node*head_ref,int value){
    struct node*ptr=create();
        if(head_ref==NULL){
            ptr->data=value;
            ptr->prev=NULL;
            ptr->next=NULL;
            return ptr;
    }
    ptr->data=value;
    ptr->next=NULL;
    struct node*p=head_ref;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->prev=p;
    return head_ref;
    
}
struct node*add_at_index(struct node*head_ref,int value,int index){
   if(index==1){
       return addbeg(head_ref,value);
   }
    int count=1;
    struct node*p=head_ref;
    while(count!=index-1){
        p=p->next;
        count++;                    // 1-Based format index//
    }
    struct node*ptr=create();
    ptr->data=value;
    ptr->next=p->next;
    ptr->prev=p;
    ptr->next->prev=ptr;
    p->next=ptr;
    return head_ref;
        
}
struct node*del_node(struct node*head_ref,int node_data){
    struct node*p=head_ref;
    if(head_ref->data==node_data){
        head_ref=head_ref->next;
        head_ref->prev=NULL;
        free(p);
        return head_ref;
    }
    struct node*ptr;
    while(p->data!=node_data){
        ptr=p;
        p=p->next;
    }
    if(p->next==NULL){
        ptr->next=NULL;
        free(p);
        return head_ref;
    }
    ptr->next=p->next;
    ptr->next->prev=ptr;
    free(p);
    return head_ref;

}
void print_linked_list(struct node*ptr){
    struct node*p;
    printf("\n(Left to right order)\n");
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        p=ptr;
        ptr=ptr->next;
    }
    printf("\n**************\n");
    printf("\n(Right to Left order)\n");

    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->prev;
    }
    
}
int main(){
    int temp,index;
    struct node*head=NULL;

    int choice;
        printf("1. For adding in begining\n2. For adding at some index\n3. For adding at end \n4. For deleting a node \n5.For printing the list\n-1. for exiting\n");
    while(choice!=-1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("For adding in begining of the list enter the value: ");
            scanf("%d",&temp);
            head=addbeg(head,temp);
            break;

            case 2:
            printf("For adding at some index enter the value and index(1-based format):\n");
            printf("Enter value of node: ");
            scanf("%d",&temp);
            printf("Enter index: ");
            scanf("%d",&index);
            head=add_at_index(head,temp,index);
            break;

            case 3:
            printf("For adding at end enter the value: ");
            scanf("%d",&temp);
            head=addend(head,temp);
            break;

            case 4:
            printf("For deletion of a node enter the value of node: ");
            scanf("%d",&temp);
            head=del_node(head,temp);
            break;

            case 5:
            printf("*****************\n");
            print_linked_list(head);
            printf("\n");
            break;

            case -1:
            exit(0);
            break;
            default:
            printf("\nENter a valid choice :( \n");
            break;

        }
        
    }
}