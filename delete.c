#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}; //insert elemnt to the beginning 
void push(struct node** headRef,int newData){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=newData;
    temp->next=*headRef;
    *headRef=temp;
}
void deleteNode(struct node **headRef,int key){
    struct node* temp=*headRef,*prevNode;
    if(temp!=NULL && temp->data==key){
        *headRef=temp->next;//changing head
        free(temp);
        return;
    }
    //changing prev->next as we need to do it so and traversing throught the list
    while(temp!=NULL && temp->data!=key){
        prevNode=temp;
        temp=temp->next;
       
    }
    if(temp==NULL) 
        return;
    prevNode->next=temp->next;;//unlinking node from the linked list
    free(temp);//free temp;
}
void printList(struct node* n){
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
    printf("\n");
}
int main(){
    struct node* head=NULL;
    push(&head,6);
    push(&head,5);
    push(&head,11);
    printList(head);
    
    deleteNode(&head,6);
    printList(head);
    deleteNode(&head,5);
    printList(head);
return 0;
}