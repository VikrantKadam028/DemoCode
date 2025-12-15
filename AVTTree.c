#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	int height;
	struct Node* left;
	struct Node* right;
};

int max(int a , int b){
	return (a>b)? a:b;
}

int getHeight(struct Node* root){
	if(root == NULL) return 0;
	return root->height;
}

int getBalance(struct Node* root){
	if(root == NULL) return 0;
	
	return getHeight(root->left) - getHeight(root->right);
}

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}

struct Node* rightRotation(struct Node* root){
	struct Node* child = root->left;
	struct Node* childRight = child->right;
	
	child->right = root;
	root->left = childRight;
	
	root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
	child->height = 1 + max(getHeight(child->left) ,getHeight(child->right));
	
	return child;
}

struct Node* leftRotation(struct Node* root){
	struct Node* child = root->right;
	struct Node* childLeft = child->left;
	
	child->left = root;
	root->right = childLeft;
	
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	child->height = 1 + max(getHeight(child->left), getHeight(child->right));
	
return child; 
}

struct Node* insert(struct Node* root, int key){
	if(root == NULL) return createNode(key);
	
	if(key < root->data){
		root->left = insert(root->left,key);
	}else if(key > root->data){
		root->right = insert(root->right, key);
	}else {
		return root;
	}
	
	
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	int balance = getBalance(root);
	
	//LL
	if(balance > 1 && key < root->left->data){
		return rightRotation(root);
	}
	
	//RR
	if(balance < -1 && key > root->right->data){
		return leftRotation(root);
	}
	
	//LR
	if(balance > 1 && key > root->left->data){
		root->left = leftRotation(root->left);
		return rightRotation(root);
	}
	
	//RL
	if(balance < -1 && key < root->right->data){
		root->right = rightRotation(root->right);
		return leftRotation(root);
	}
	return root;
}

void inorder(struct Node* root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

int main(){
	struct Node* root = NULL;
	root = insert(root, 10);
   	root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    printf("AVL TREE: ");
    inorder(root);
	return 0;
}
