#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node * head = NULL;
struct Node* GetNewNode(int x){
    struct Node * newNode = (struct Node*)malloc(sizeof (struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void InsertAtHead(int x){
    struct Node* newNode = GetNewNode(x);
    if(head ==NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void InsertAtTail(int x){
    struct Node* newNode = GetNewNode(x);
    struct Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
}
void print(){
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Reverseprint(){
    struct Node* temp = head;
    printf("Reverse: ");
    if(temp == NULL)    return;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main ()
{
    InsertAtHead(2);print();Reverseprint();
    InsertAtHead(4);print();Reverseprint();
    InsertAtHead(6);print();Reverseprint();
    InsertAtHead(3);print();Reverseprint();
    InsertAtHead(5);print();Reverseprint();
    InsertAtTail(2);print();Reverseprint();
    InsertAtTail(3);print();Reverseprint();
    InsertAtTail(7);print();Reverseprint();
    return 0;
}