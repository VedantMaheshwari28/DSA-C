// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *previous;
};
void display(struct node *head) {
    struct node *start = head;
    while (start != NULL) { // Use while loop directly on the linked list
        printf("%d\n", start->data);
        start = start->next;
    }
}
struct node * deleteStart(struct node* start){
    if(start ==NULL){
        return start;
    }
    struct node* NodeToBeDeleted=start;
    start = start -> next;
    start -> previous = NULL;
    free(NodeToBeDeleted);
    return start;
}
struct node * deleteAtIndex(struct node*start,int index){
    if(index<0){
        printf("INVALID");
        return start;
    }

    else{
    struct node *Delete,*traverse=start;
    int i=0;
    if(start==NULL){
        return NULL;
    }
    if(start->next == NULL){
        free(start);
        return NULL;
    }
    while(i!=index-1 && traverse -> next !=NULL){
        traverse = traverse -> next;
        i++;
    }
    Delete = traverse -> next;
    traverse -> next = Delete -> next;
    if(Delete->next != NULL){
        Delete -> next -> previous = traverse;
    }
    free(Delete);
    return start;
    }
}
struct node * deleteTheEnd(struct node*start){
    struct node* Delete;
    struct node *traverse=start;
    while(traverse->next->next!=NULL){
        traverse = traverse->next;
    }
    Delete = traverse ->next;
    traverse -> next = NULL;
    return start;
}
int main() {
    struct node *head = NULL, *second, *third;

    // Allocate memory for nodes
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // Initialize node values
    head->data = 6;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 99;
    third->next = NULL;
    // head = insertAtStart(head,12);
    // display(head);
    head = deleteAtIndex(head , 2);
    display(head);
    return 0;
}
