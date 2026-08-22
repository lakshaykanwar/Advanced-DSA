#include<stdio.h>
int ar[100], top=-1, size;

void push();
void pop();
void peek();
void traverse();

void main(){
  int i,n;
  printf("Enter the size of stack: ");
  scanf("%d",&n);
  size=n;
  for(i=0;i<size;i++){
      push();
  }
  traverse();
  pop();
  peek();
  traverse();
}

void push(){
    int n;
    if(top==size-1){
        printf("Stack is Full!");
        return;
    } else {
        printf("Enter elements: ");
        scanf("%d",&n);
        top=top+1;
        ar[top]=n;
    }
}

void pop(){
    int m;
    if(top==-1){
        printf("Stack is empty!");
        return;
    } else {
        m=ar[top];
        printf("\nDeleted element: %d\n",m);
        top--;
    }
}

void peek(){
    if(top==-1){
        printf("Stack is empty!");
        return;
    } else {
        printf("Top element: %d\n",ar[top]);
    }
}

void traverse(){
    int i;
    if(top==-1){
        printf("Stack is empty!");
        return;
    } else {
        printf("\nStack elements are: ");
        for(i=top;i>=0;i--){
            printf("%d ",ar[i]);
        }
    }
}