#include <stdio.h>
#include <stdlib.h>
//memory equip is more then singly
struct node{
    int data;
    struct node *next;
    struct node *previous;
};
void display(struct node* start){
    struct node *ptr = start;
    while(ptr!=0){
        printf("%d \n ",ptr -> data);
        ptr = ptr -> next;
    }
}
int count(struct node *start){
    int counter =0;
    struct node * ptr = start;
    while(ptr!=0){
        ptr =ptr -> next;
        counter++;
    }
    return counter;
}
struct node * insertAtStart(struct node*start, int data){
    struct node *NodeToBeAdded=(struct node*)malloc(sizeof(struct node));
    struct node *ptr=start;
    NodeToBeAdded -> data =data;
    ptr -> previous = NodeToBeAdded;//head ka pich wala |*|data|*| wale newnode ka address
    NodeToBeAdded -> next = ptr;//new node ka aage wala |0|data|*| ye aapne aagr yahi head ka address le
    return NodeToBeAdded;
}
struct node * insertAtEnd(struct node *start,int data){
    struct node* NodeToBeAdded=(struct node*)malloc(sizeof(struct node));
    struct node *traverse = start;
    NodeToBeAdded->data=data;
    int a=0,b=count(start);
    while(a!=b-1){
        a++;
        traverse=traverse->next;
    }
    NodeToBeAdded->previous = traverse;
    NodeToBeAdded->next = traverse ->next;
    traverse -> next = NodeToBeAdded;
    NodeToBeAdded->next=0;
    return start;
}
struct node * insertAtIndex(struct node* start,int data,int index){
    int b=count (start);
    if(index >b){
        printf("INVALID");
    }
    else{
        struct node * traverse=start,*nexttraverse;
        struct node * NodeToBeAdded = (struct node*)malloc(sizeof(struct node));
        int a=0;
        NodeToBeAdded->data=data;
        while(a!=index-1){
            a++;
            traverse = traverse ->next;
        }
        nexttraverse = traverse -> next;
        NodeToBeAdded -> previous =traverse;
        NodeToBeAdded ->next = nexttraverse;
        nexttraverse->previous=NodeToBeAdded;
        traverse->next=NodeToBeAdded;
        return start;
    }
}
int main(){
    struct node *newnode,*temp,*head;
    head =0;
    int d;
    int choice =1;
    while(choice){
    newnode = (struct node*)malloc(sizeof(newnode));
    printf("Enter your data :");
    scanf("%d", &d);
    newnode->data =d;
    newnode->next = 0;
    newnode ->previous =0;
    if(head==0){
        head=temp=newnode;
    }
    else{
        temp->next = newnode;
        newnode -> previous = temp;
        temp = temp-> next;
    }
    printf("Do you want to continue(0,1)? :");
    scanf("%d", &choice );
    }
    head = insertAtIndex(head,99,3);
    display(head);
    return 0;
}
