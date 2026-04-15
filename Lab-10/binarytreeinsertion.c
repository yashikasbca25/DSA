#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value; 
    newNode->left = NULL;      
    newNode->right = NULL;     
    return newNode;
}
struct Node* queue[100];
int front = -1, rear = -1;
void enqueue(struct Node* node){
    if(front == -1) front = 0;
    queue[++rear] = node;
}
struct Node* dequeue(){
    return queue[front++];
}
struct Node* insert(struct Node* root, int value){
    struct Node* newNode = createNode(value);
    if(root == NULL)
        return newNode;
    front = rear = -1;
    enqueue(root);
    while(front <= rear){
        struct Node* temp = dequeue();
        if(temp->left == NULL){
            temp->left = newNode;
            break;
        } else {
            enqueue(temp->left);
        }
        if(temp->right == NULL){
            temp->right = newNode;
            break;
        } else {
            enqueue(temp->right);
        }
    }
    return root;
}
void inorder(struct Node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct Node* root){
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main(){
    struct Node* root = NULL;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    return 0;
}