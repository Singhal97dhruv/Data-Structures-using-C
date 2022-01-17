#include<stdio.h>           //Singhal SaaB
#include<stdlib.h>
struct node{
    int front;
    int rear;
    int capacity;
    int *arr;    
};
struct node*create(int capacity){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->front=-1;
    new->rear=-1;
    new->capacity=capacity;
    new->arr=(int*)malloc(capacity*sizeof(int));
    return new;
}

struct node*enqueue(struct node*Queue,int value){
    if(Queue->rear==-1){
        Queue->rear=Queue->front=0;
        Queue->arr[Queue->rear]=value;
        return Queue;
    }
    if(Queue->front==(Queue->rear+1)%Queue->capacity){
        printf("Queue is full\n");
        return Queue;
    }
    
    Queue->rear=(Queue->rear+1)%(Queue->capacity);
    Queue->arr[Queue->rear]=value;
    return Queue;
}
struct node*dequeue(struct node*Queue){
    if(Queue->front==-1){
        printf("Queue is empty\n");
        return Queue;
    }
    if(Queue->front==Queue->rear){
        printf("%d is dequeued from the queue\n",Queue->arr[Queue->front]);
        Queue->front=Queue->rear=-1;
        return Queue;
    }
    printf("%d is dequeued from the Queue\n",Queue->arr[Queue->front]);
    Queue->front=(Queue->front+1)%Queue->capacity;
    return Queue;
    
}
void print_Queue(struct node*p){
    if(p->rear==-1){
        printf("Queue is empty\n");
        return ;
    }
    if(p->front<=p->rear){
    for(int i=p->front;i<=p->rear;i++){
        printf("%d\t",p->arr[i]);
    }
    }
    else{
        for(int i=p->front;i<p->capacity;i++){
            printf("%d\t",p->arr[i]);
        }
        for(int i=0;i<=p->rear;i++){
            printf("%d\t",p->arr[i]);
        }
    }
    printf("\n");
}
int main(){
    int n, temp,tmp;
    struct node*Queue;
    printf("Enter the size of Queue of which you want to make Queue: ");
    scanf("%d",&n);
    Queue=create(n);
    Queue=enqueue(Queue,67);
    int choice;
    printf("1.)For entering elements in Queue\n2.)For dequeueing from Queue\n3.)For printing the Queue\n-1.)For exiting the loop\n");
    while(choice!=-1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter how many elements you want to enter in the Queue: ");
            scanf("%d",&tmp);
            printf("Enter elements: ");
            for(int i=0;i<tmp;i++){
                scanf("%d",&temp);
                Queue=enqueue(Queue,temp);
            }
            break;
            case 2:
            Queue=dequeue(Queue);
            break;
            case 3:
            print_Queue(Queue);
            break;
            case -1: 
            exit(0);
            default:
            printf("Please Enter valid choice:\n");
        }    
    }
}
