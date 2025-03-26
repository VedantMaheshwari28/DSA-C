#include <stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node * insertNodeInBetween(struct node *start ,int data,int index){
    struct node *traverse = start;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    int i=0;
    ptr->info=data;
    while(i!=index-1){
            traverse=traverse->link;
            i++;
    }
    ptr ->link=traverse -> link;
    traverse-> link =ptr;
    return start;
}
struct node * interNodeAtStart(struct *start,int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> info =data;
    ptr -> link = start ;
    return ptr;

}

void display(struct node *start){
    struct node *p=start;
    while(p!=NULL){
        printf("%d \n",p->info);
        p=p->link;
    }
}
int count(struct node *start){
    int counter =0;
    struct node *p=start;
    while(p!=NULL){
        p=p->link;
        counter++;
    }
    return counter;
}

struct node * insertNodeAtEnd(struct node *Start,int data){
    struct node *traverse = Start;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> info =data;
    int a=0;
    int b=count(traverse);
    while(a!=b-1){
        a++;
        traverse = traverse ->link;
    }
    traverse -> link = ptr;
    ptr-> link = NULL;
    return Start;
}

int main() {
    struct node *head,*second,*third;
    head = (struct node*)malloc(sizeof(struct node*));
    second = (struct node*)malloc(sizeof(struct node*));
    third = (struct node*)malloc(sizeof(struct node*));

    head->info = 77;
    head->link = second;

    second->info =66;
    second->link = third;

    third->info = 7;
    third->link = NULL;
    //head = insertNodeInBetween(head,99,2);
    //display(head);
    head = insertNodeAtEnd(head ,70);
    display(head);
    return 0;

}


