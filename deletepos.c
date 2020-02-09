/*If node to be deleted is root, simply delete it.
 To delete a middle node, we must have pointer to the node previous to the node to be deleted.
  So if positions is not zero, we run a loop position-1 times and get pointer to the previous node.*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void push(struct node** headref,int newData){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=newData;
    temp->next=*headref;
    *headref=temp;
}
void printList(struct node* n){
    while(n!=NULL){
        printf("%d ",(n->data));
        n=n->next;
    }
    printf("\n");
}
void printPos(struct node** headref,int position){
    if(*headref==NULL){
        return;      //if linked list is empty return nothing
    }
    struct node* temp=*headref;
    if(position==0){
        *headref=temp->next;
        free(temp);
        return;
    }
    for(int i=0;temp!=NULL && i<position-1;i++)//find previous node of node to be deleted
        temp=temp->next;
    if(temp==NULL || temp->next==NULL)//if position>number of node just return nothing
        return;
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    struct node* next=temp->next->next;
    free(temp->next);
    temp->next=next;// Unlink the deleted node from list 
}

int main(){
    struct node* head=NULL;
    push(&head,10);
    push(&head,11);
    push(&head,12);
    push(&head,13);
    printList(head);
    printPos(&head,3);
    printList(head);
     printPos(&head,1);
     printList(head);
}

