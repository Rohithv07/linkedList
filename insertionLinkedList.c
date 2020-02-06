#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void push(struct node** headRef,int newData){      //insertion at beginning
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=newData;
    temp->next=(*headRef);
    *headRef=temp;
}
void append(struct node** headRef,int newData){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* last=*headRef;
    temp->data=newData;
    temp->next=NULL;
    if(*headRef==NULL){//if list is empty,make the new node as head
        *headRef=temp;
        return;
    }
    while(last->next!=NULL){//else traverse till last node
        last=last->next;
        last->next=temp;
        return;
    }

}
void insertAfter(struct node* element,int newData){
    if(element->next==NULL){
        return;
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=newData;
    temp->next=element->next;
    element->next=temp;
}
void printList(struct node* n){
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
}
int main(){
    struct node* head=NULL;
    push(&head,7);
    push(&head,1);
    append(&head,5);
    insertAfter(head->next,4);
    insertAfter(head->next,8);
    printList(head);
    return 0;

}