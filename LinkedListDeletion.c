#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node * DeleteFromStart(struct Node *head){
    struct Node *ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

struct Node * deleteAtIndex(struct Node *start,int index){
    struct Node *Traverse = start;
    struct Node *NodeToBeDeleted;
    int i=0;
    while(i!=index-1){
        Traverse= Traverse -> next;
        i++;
    }
    NodeToBeDeleted = Traverse->next;
    Traverse->next=NodeToBeDeleted->next;
    free(NodeToBeDeleted);
    return start;
}
struct Node * deleteLastElement(struct Node *head){
    struct Node *NodeToBeDeleted;
    struct Node * traverse=head;
    int a=1,b =count(head);
    while(a!=b-1){
        traverse= traverse-> next;
        a++;
    }
    NodeToBeDeleted = traverse-> next;
    traverse -> next = NULL;
    free(NodeToBeDeleted);
    return head;
}

struct Node * deleteElementByData(struct Node *start , int data){
    struct Node *traverse= start;
    int i=0;
    while(traverse->data!=data){
        i++;
        traverse= traverse -> next;
    }
    struct Node *updated = deleteAtIndex(start,i);
    return updated;
}
int count(struct Node *start){
    int counter =0;
    struct Node *ptr = start;
    while(ptr!=NULL) {
        ptr = ptr -> next;
        counter++;
    }
    return counter;
}

void display (struct Node *start){
    struct Node *ptr = start;
    while(ptr!=NULL) {
        printf("%d \n",ptr->data);
        ptr = ptr -> next;
    }
}