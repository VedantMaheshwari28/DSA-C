#include <stdio.h>
#define N 5
int cqueue[5];
int front=-1,rear=-1,item;
int isFull(){
    return ((front==0&&rear==N-1)||(front==rear+1)) ;
}
int isEmpty(){
    return front==-1&&rear==-1;
}
int enqueue(int num){
    if(rear==-1&&front==-1){
        front=rear=0;
        cqueue[rear]=num;
    }
    else if(isFull()){
            printf("OVERFLOW\n");
        }
    else
    {
        rear=(rear+1);
        cqueue[rear]=num;
    }
}
int dequeue(){
    if(isEmpty()){
        printf("UNDERFLOW\n");
        return -1;
    }
    else if(rear==front){
            item=cqueue[front];
            front=rear=-1;
            return item;
        }
    else {
        item=cqueue[front];
        front =(front+1);
        return item;
    }
}
