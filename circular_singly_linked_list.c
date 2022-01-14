#include<stdio.h>                   //Singhal SAAB
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*create(){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    return new;
}
struct node*addbeg(struct node*last_ref,int value){
    struct node*ptr=create();
    ptr->data=value;
        if(last_ref==NULL){
            ptr->next=ptr;
            return ptr;
    }
    ptr->next=last_ref->next;
    last_ref->next=ptr;
    return last_ref;
}
struct node*addend(struct node*last_ref,int value){
    struct node*ptr=create();
            ptr->data=value;
        if(last_ref==NULL){
            ptr->next=ptr;
            return ptr;
    }
    ptr->next=last_ref->next;
    last_ref->next=ptr;
    last_ref=ptr;
    return last_ref;
    
}
struct node*add_at_index(struct node*last_ref,int value,int index){
    int count =1;
    struct node*ptr=last_ref;
    while(count!=index){
        ptr=ptr->next;
        count++;
    }
    struct node*p=create();
    p->data=value;
    p->next=ptr->next;
    ptr->next=p;
    return last_ref;
}
void print_linked_list(struct node*last_ref){
    struct node*p=last_ref;
    do{
        p=p->next;
        printf("%d\t",p->data);
    }
    while(p!=last_ref);
}
struct node*del_node(struct node*last_ref,int node_data){
    struct node*ptr=last_ref;
    if(last_ref->data==node_data){
    while(ptr->next!=last_ref){
        ptr=ptr->next;
    }
    struct node*temp=ptr->next;
    ptr->next=last_ref->next;
    free(temp);
    last_ref=ptr;
    return last_ref;
    
    }
    
    struct node*p=last_ref->next;
    while(p->data!=node_data){
        ptr=p;
        p=p->next;
    }
    ptr->next=p->next;
    free(p);
    return last_ref;

}
int main(){
    int temp,index;
    struct node*last=NULL;

    int choice;
        printf("1. For adding in begining\n2. For adding at some index\n3. For adding at end \n4. For deleting a node \n5.For printing the list\n-1. for exiting\n");
    while(choice!=-1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("For adding in begining of the list enter the value: ");
            scanf("%d",&temp);
            last=addbeg(last,temp);
            break;

            case 2:
            printf("For adding at some index enter the value and index(1-based format):\n");
            printf("Enter value of node: ");
            scanf("%d",&temp);
            printf("Enter index: ");
            scanf("%d",&index);
            last=add_at_index(last,temp,index);
            break;

            case 3:
            printf("For adding at end enter the value: ");
            scanf("%d",&temp);
            last=addend(last,temp);
            break;

            case 4:
            printf("For deletion of a node enter the value of node: ");
            scanf("%d",&temp);
           last=del_node(last,temp);
            break;

            case 5:
            printf("*****************\n");
            print_linked_list(last);
            printf("\n");
            break;

            case -1:
            exit(0);
            break;
            default:
            printf("Please Enter a valid choice :(\n");

        }
        
    }
}