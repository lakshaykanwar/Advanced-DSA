#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int priority;
    struct node *ptr;
};
struct node *front=NULL;

void enqueue();
void dequeue();
void display();

void main(){
    int ch;
    printf("\nMenu\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
            printf("\nInvalid Choice!\n");
            
        }
    }
}

void enqueue(){
    int value, priority;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&value);
    printf("Enter the priority: ");
    scanf("%d",&priority);
    new->data=value;
    new->priority=priority;
    new->ptr=NULL;
    
    if(front==NULL || priority<front->priority){
        new->ptr=front;
        front=new;
    } else {
        struct node *temp=front;
        while(temp->ptr!=NULL && temp->ptr->priority <= priority){
            temp=temp->ptr;
        }
        new->ptr=temp->ptr;
        temp->ptr=new;
    }
    printf("\n");
}

void dequeue(){
    if(front==NULL){
        printf("Priority queue is empty!\n");
        return;
    }
    struct node *temp=front;
    printf("Deleted: %d\n",temp->data);
    front=front->ptr;
    free(temp);
    printf("\n");
}

void display(){
    if(front==NULL){
        printf("Priority Queue is empty!\n");
        return;
    }
    struct node *temp=front;
    printf("\nPriority Queue:\n");
    while(temp!=NULL){
        printf("Data=%d, priority=%d\n",temp->data,temp->priority);
        temp=temp->ptr;
    }
    printf("\n");
}