#include<stdio.h>>
#define N 5
int stack[N];
int top =-1;
void push(int a){
    if(top==N-1){
        printf("Overflow");
    }
    else{
        top++;
        stack[top]=a;
        }
    }
int isEmpty(){
        if(top==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
int pop(){
        if(isEmpty()){
            printf("Underflow");
        }
        else{
            int item;
            item = stack[top];
            top--;
        }
    }
void isFull(){
        if(isEmpty()) {
            printf("UNDERFLOW");
        }
        else {
             if(top==N-1){
                printf("STACK US FULL");
                printf("\n");
             }
        }
}
int display(){
    for(int i=top;i>=0;i--){
        printf("%d",stack[i]);
        printf("\n");
    }
    return 0;
}
void peek(){
    if(isEmpty()){
        printf("NO TOP");
    }
    else{
        printf("%d",stack[top]);
    }
}
