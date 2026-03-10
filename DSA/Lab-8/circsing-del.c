#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void display(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("(back to start)\n");
}
void insertEnd(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
void deleteStart(){
    if(head == NULL){
        printf("List empty\n");
        return;
    }
    struct Node* temp = head;
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }
    struct Node* last = head;
    while(last->next != head){
        last = last->next;
    }
    head = head->next;
    last->next = head;
    free(temp);
}
void deleteEnd(){
    if(head == NULL){
        printf("List empty\n");
        return;
    }
    struct Node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    struct Node* last = temp->next;
    temp->next = head;
    free(last);
}
void deletePosition(int pos){
    struct Node* temp = head;
    for(int i=1;i<pos-1;i++){
        temp = temp->next;
    }
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}
int main(){
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    printf("Original List:\n");
    display();
    deleteStart();
    printf("\nAfter deleting start:\n");
    display();
    deleteEnd();
    printf("\nAfter deleting end:\n");
    display();
    deletePosition(2);
    printf("\nAfter deleting position 2:\n");
    display();
    return 0;
}
