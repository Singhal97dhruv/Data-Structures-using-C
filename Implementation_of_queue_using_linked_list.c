#include<stdio.h>           //Singhal SAAB
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct queue{
    struct node*front,*rear;
};
struct node*createnode(int key){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=key;
    new->next=NULL;
    return new;
}
struct queue*create_queue(){
    struct queue*new=(struct queue*)malloc(sizeof(struct queue));
    new->front=new->rear=NULL;
    return new;
}
void enqueue(struct queue*Queue,int value){
    struct node*new_node=createnode(value);
    if(Queue->rear==NULL){
        Queue->front=Queue->rear=new_node;
        return;
    }
    Queue->rear->next=new_node;
    Queue->rear=new_node;
    return;
}
void dequeue(struct queue*Queue){
    if(Queue->front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node*temp=Queue->front;
    Queue->front=Queue->front->next;
    printf("%d is dequeued from the Queue\n",temp->data);
    if(Queue->front==NULL){
        Queue->rear=NULL;
    }
}
void print_queue(struct queue*p){
    if(p->front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node*temp=p->front;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    struct queue*Queue=create_queue();
   int temp,choice;
   printf("1.)For enqueueing the Queue\n2.)For Dequeueing from the Queue\n3.)For printing the Queue\n-1.)For exiting the loop\n");
   while(choice!=-1){
       printf("Enter your choice: ");
       scanf("%d",&choice);
       switch (choice)
       {
       case 1:
        printf("Enter the value to be inserted in the queue: ");
        scanf("%d",&temp);
        enqueue(Queue,temp);
        break;
       case 2:
       dequeue(Queue);
       break;
       case 3:
       print_queue(Queue);
       break;
       case -1:
       exit(0);
       break;
       default:
       printf("Enter valid choice:\n");
           break;
       }
       
   }
}
