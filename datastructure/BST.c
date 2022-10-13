#include <stdio.h>
//#include <queue>
struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
};
struct BstNode* root = NULL;
struct BstNode* GetNewNode(int x){
    struct BstNode* new = (struct BstNode*)malloc(sizeof(struct BstNode*));
    new->data = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}
struct BstNode* Insert(struct BstNode* root,int data){
    if(root == NULL){//empty tree
    root = GetNewNode(data);
    }
    else if (data <= root->data){
        root->left = Insert(root->left,data);
    }
    else {
        root->right = Insert(root->right,data);
    }
    return root;
}
struct BstNode* FindMin(struct BstNode* root){
    if(root == NULL){
        return;
    }
    struct BstNode* current = root;
    while(current->left != NULL){current = current->left;}
    return current; 
}
int FindMax(struct BstNode* root){
    if(root == NULL){
        return;
    }
    struct BstNode* current = root;
    while(current->right != NULL){current = current->right;}
    return current->data; 
}
int FindHeight(struct BstNode* root){
    if(root == NULL)return -1;
    int LeftHeight = 0;
    int RightHeight = 0;
    LeftHeight = FindHeight(root->left);
    RightHeight = FindHeight(root->right);
    return max(LeftHeight,RightHeight)+1; 
}
struct BstNode* Find(struct BstNode* root, int data){
    if(root == NULL)return root;
    else if (data < root->data)root->left = Find(root->left,data);
    else if (data > root->data)root->right = Find(root->right,data);
    else return root;
}
// void LevelOrder(struct BstNode* root){
//     if(root == NULL)return;
//     queue<struct BstNode* root>Q;
//     Q.push(root);
//     while(!Q.empty()){
//         struct Node* current = Q.front();
//         printf("%d ",current->data);
//         if(current->left != NULL)Q.push(current->left);
//         if(current->right != NULL)Q.push(current->right);
//         Q.pop();
//     }
// }
void Preorder(struct BstNode* root){
    if(root == NULL)return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(struct BstNode* root){
    if(root ==NULL)return;
    Preorder(root->left);
    printf("%d ",root->data);
    Preorder(root->right);
}
void Postorder(struct BstNode* root){
    if(root ==NULL)return;
    Preorder(root->left);
    Preorder(root->right);
    printf("%d ",root->data);
}
int IsBST(struct BstNode* root,int min,int max){
    if(root == NULL)return 1;
    if (root->data > min
        && root->data < max
        &&IsBST(root->left,min,root->data)
        &&IsBST(root->right,root->data,max))
        return 1;
        else return 0;
}
struct Node* Delete(struct BstNode* root,int data){
    if(root == NULL)return root;
    else if (data < root->data)root->left = Delete(root->left,data);
    else if (data > root->data)root->right = Delete(root->right,data);
    else{
        if(root->left ==NULL && root->right == NULL){
            free(root);
            root = NULL;
            return root;
        }
            else if(root->left == NULL){
                struct BstNode* temp = root;
                root = root->right;
                free(temp);
                return root;
            }
            else if(root->right == NULL){
                struct BstNode* temp = root;
                root = root->left;
                free(temp);
                return root;
            }
            else {
                struct  BstNode* temp = FindMin(root->right);
                root->data = temp->data;
                root->right = Delete(root->right,temp->data);
            }
        }
        return root;
}

struct BstNode* Getsuccessor(struct BstNode* root,int data){
    struct BstNode* current = Find(root,data);
    if(current == NULL)return NULL;
    if(current->right != NULL)return FindMin(root->right);
    else{
        struct BstNode* successor = NULL;
        struct BstNode* ancestor = root;
        while(ancestor != current){
            if (current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

