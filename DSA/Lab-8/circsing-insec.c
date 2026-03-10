#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to start)\n");
}
void insertEnd(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
void insertStart(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}
void insertPosition(int data, int pos) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    printf("Circular Singly Linked List before insertion:\n");
    display();
    insertStart(5);
    printf("\nAfter insertion at start:\n");
    display();
    insertEnd(50);
    printf("\nAfter insertion at end:\n");
    display();
    insertPosition(25, 3);
    printf("\nAfter insertion at position 3:\n");
    display();

    return 0;
}