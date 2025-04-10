#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int count(struct node *start){
    struct node *traverse=start;
    int counter =0;
    while(traverse!=0){
        counter++;
        traverse = traverse -> next;
    }
    return counter;
}
void *reverseLinkedList(struct node*start){
    struct node *traverse = start;

}
