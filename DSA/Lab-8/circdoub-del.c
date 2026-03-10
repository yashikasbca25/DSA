```c
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
void display(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insertEnd(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteStart(){
    if(head == NULL){
        printf("List empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if(head != NULL)
        head->prev = NULL;
    free(temp);
}
void deleteEnd(){
    if(head == NULL){
        printf("List empty\n");
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    free(temp);
}
void deletePosition(int pos){
    struct Node* temp = head;
    for(int i=1;i<pos;i++){
        temp = temp->next;
    }
    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    if(temp == head)
        head = temp->next;
    free(temp);
}
int main(){
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    printf("Original Doubly Linked List:\n");
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
