//USING ARRAY
// #include <stdio.h>
// #define MAX_SIZE 101
// int A[MAX_SIZE];
// int front = NULL;
// int rear = NULL;

// void Enqueue(int x){
//     if ((rear+1) % MAX_SIZE == front)return;
//     else if(front == rear == NULL){
//         front = 0;rear = 0;
//     }
//     else {
//         rear = (rear+1) % MAX_SIZE;
//     }
//     A[rear] = x;
// }
// void Dequeue (){
//     if(front == rear == NULL)return;
//     else if (front == rear){
//         front = NULL;rear = NULL;
//     }
//     else front = (front +1) % MAX_SIZE;
// }
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node * front = NULL;
struct Node * rear = NULL;
void Enqueue(int x){
    struct Node * temp = (struct Node*)malloc(sizeof (struct Node));
    temp->data = x;
    temp->next = NULL;
    if(front == NULL &&rear == NULL){
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
void Dequeue(){
    struct Node* temp = front;
    if(front == NULL)return;
    if(front == rear)   front = rear = NULL;
    else front = front->next;
    free (temp);
}