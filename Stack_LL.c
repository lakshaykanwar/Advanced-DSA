#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}; struct node *top=NULL;

void push();
void pop();
void peek();
void traverse();

void main(){
    int i,n;
    printf("Enter the size of stack: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        push();
    }
    traverse();
    pop();
    peek();
    traverse();
}

void push(){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Stack is overflow!");
    } else {
        printf("Enter the data: ");
        scanf("%d",&temp->data);
        temp->link=top;
        top=temp;
    }
}

void pop(){
    if(top==NULL){
        printf("Stack is empty!");
    } else {
        struct node *temp=top;
        printf("\nDeleted Element: %d\n",temp->data);
        top=top->link;
        free(temp);
    }
}

void peek(){
    if(top==NULL){
        printf("Stack is empty!");
    } else {
        printf("Top element: %d\n",top->data);
    }
} 

void traverse(){
    if(top==NULL){
        printf("Stack is empty!");
    } else {
        struct node *temp=top;
        printf("\nDisplay elements: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->link;
        }
    }
}