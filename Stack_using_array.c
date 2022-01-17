#include<stdio.h>               //SInghal SAab
#include<stdlib.h>
struct node{
    int top;
    int capacity;
    int *arr;
};
struct node*create(int size){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->top=-1;
    new->capacity=size;
    new->arr=(int*)malloc(new->capacity*sizeof(int));
    
    return new;
}
struct node*push(struct node*head_ref,int value){
    if(head_ref->top==head_ref->capacity-1){
        printf("StACK overflow\n");
        return head_ref;
    }
    head_ref->top++;
    (head_ref->arr)[head_ref->top]=value;
    printf("%d is pushed in the stack\n",head_ref->arr[head_ref->top]);
    return head_ref;
}
struct node*pop(struct node*head_ref){
    if(head_ref->top==-1){
        printf("Stack underflow\n");
        return head_ref;
    }
    int tmp=head_ref->arr[head_ref->top--];
    printf("%d is popped out from the stack\n",tmp);
    return head_ref;
}
void print_stack(struct node*ref){
    if(ref->top==-1){
        printf("STACK underflow\n");
        return;
    }
    for(int i=ref->top;i>=0;i--){
        printf("%d\t",ref->arr[i]);
    }
    printf("\n");
}
int main(){
    int n,temp;
    int k;
    printf("Enter the size of the Stack: ");
    scanf("%d",&n);
    struct node*head=NULL;
    head=create(n);
    int choice;
    printf("1.)For pushing elements in the Stack\n2.)For popping out element from the Stack\n3.)For printing the whole STack\n-1.)For exiting the loop\n");
    while(choice!=-1){
        printf("ENter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("How many elements you want to push in the Stack: ");
            scanf("%d",&k);
            for(int i=0;i<k;i++){
                printf("Enter element-> ");
                scanf("%d",&temp);
                head=push(head,temp);
            }
            break;
        case 2:
            head=pop(head);
            break;
        case 3:
            print_stack(head);
            break;
        case -1:
            exit(0);
        default:
            printf("Enter Valid choice :(\n");
            break;
        }
    }

}
