#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left = newNode->right=NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value){
    if(root==NULL) return createNode(value);
    if(value < root->data)root->left=insert(root->left, value);
    else if(value > root->data)root->right=insert(root->right, value);
    return root;
}
struct Node* find(struct Node*root){
    while(root && root->left!=NULL)root=root->left;
    return root;
}
struct Node* delete(struct Node*root, int value){
    if(root==NULL) return root;
    if(value < root -> data)root->left = delete(root-> left, value);
    else if(value < root -> data)root->right = delete(root-> right, value);
    else{
        if(root->left == NULL) {struct Node* temp=root->right; free(root);return temp;}
        else if(root->right == NULL) {struct Node* temp=root->left; free(root);return temp;}
        struct Node* temp=find(root->right); root->data=temp->data; root->right=delete(root->right,temp->data);
        }
        return root;
}
struct Node* search(struct Node* root, int key){
    if(root==NULL||root-> data==key) return root;
    if(key<root->data)return search(root->left,key);
    else return search(root->right,key);
}
void inorder(struct Node* root){
    if(root!=NULL){ inorder(root->left); printf("%d",root-> data); inorder(root->right);}
}
void preorder(struct Node* root){
    if(root!=NULL){printf("%d",root-> data);preorder(root->left); preorder(root->right);}
}
void postorder(struct Node* root){
    if(root!=NULL){ postorder(root->left); postorder(root->right);printf("%d",root-> data); }
}
int main(){
    struct Node* root=NULL; int choice, value;
    while(1){
        printf("\n----Menu----\n");                         
        printf("1.insert \n2.delete\n3.search\n4.Inorder \n5.preorder\n6.Postorder\n7.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        if(choice>=1 && choice <=3){
         printf("enter value:");scanf("%d",&value);}
        switch(choice){
            case 1:root=insert(root,value);break;
            case 2:root=delete(root,value);break;
            case 3:printf(search(root,value)?"Found!\n": "Not found!\n"); break;
            case 4:printf("Inorder:");inorder(root); printf("\n");break;
            case 5:printf("Preorder:");preorder(root); printf("\n");break;
            case 6:printf("Postorder:");postorder(root); printf("\n");break;
            case 7:printf("!!!!!Exited from the Program!!!!!\n");exit(0);
            default: printf("invalid Option!\n");
        }
    } while (choice !=7);
    return 0;
}