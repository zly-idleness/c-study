#include <stdio.h>
// using array
// #define MAX_SIZE 101
// int A[MAX_SIZE];
// int top = -1;
// void push(int x){
//     if(top == MAX_SIZE -1){
//         printf(":Error: stackoverflow\n");
//         return;
//     }
//     A[++top] = x;
// }
// void pop(){
//     if(top == -1){
//         printf("Error: No element to pop\n");
//         return;
//     }
//     top--;
// }
// int Top (){
//     return A[top];
// }
#include <stdlib.h>
struct Node {
    int data;
    struct Node* link;
};
struct Node * top = NULL;
void push(int x){
    struct Node * temp = (struct Node*)malloc(sizeof (struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}
void pop(){
    struct Node *temp;
    if(top == NULL)    return;
    temp = top;
    top = top ->link;
    free(temp);
}
int Top(){
    return top->data;
}
int Isempty(){
    if(top == NULL)return 1;
    else return -1;
}