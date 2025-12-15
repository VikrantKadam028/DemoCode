#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Stack{
    int top;
    int size;
    struct Node** arr;
};

int isEmpty(struct Stack *s){
    return s->top == -1;
}

int isFull(struct Stack *s){
    return s->top == s->size - 1;
}

void push(struct Stack *s, struct Node* node){
    if(!isFull(s)){
        s->arr[++s->top] = node;
    }
}

struct Node* pop(struct Stack *s){
    if(isEmpty(s))
        return NULL;
    return s->arr[s->top--];
}

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data){
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorderRecursive(struct Node* root){
    if(root != NULL){
        inorderRecursive(root->left);
        printf("%d ", root->data);
        inorderRecursive(root->right);
    }
}

void mirrorImage(struct Node* root){
    if(root != NULL){
        struct Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        mirrorImage(root->left);
        mirrorImage(root->right);
    }
}

void inOrder(struct Node* root, struct Stack *s){
    while(1){
        if(root != NULL){
            push(s, root);       
            root = root->left;
        }else{
            if(isEmpty(s))
                break;  

            root = pop(s);        
            printf("%d ", root->data);
            root = root->right;
        }
    }
}

void preOrder(struct Node* root,struct Stack *s){

	push(s, root);
	while(!isEmpty(s)){
		root = s->arr[s->top];
		pop(s);
		printf("%d ",root->data);
		
		if(root->right != NULL){
			push(s, root->right);
		}
		if(root->left != NULL){
			push(s, root->left);
		}
	}
	
}

void postOrder(struct Node* root, struct Stack* s1){
    if(root == NULL) return;

    struct Stack *s2 = (struct Stack*)malloc(sizeof(struct Stack));
    s2->size = 10;
    s2->top = -1;
    s2->arr = (struct Node**)malloc(s2->size * sizeof(struct Node*));

    push(s1, root);

    while(!isEmpty(s1)){
        root = pop(s1);
        push(s2, root);

        if(root->left != NULL){
            push(s1, root->left);
        }
        if(root->right != NULL){
            push(s1, root->right);
        }
    }

    while(!isEmpty(s2)){
        struct Node* node = pop(s2);
        printf("%d ", node->data);
    }
}


int main(){
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size = 50;
    s->top = -1;
    s->arr = (struct Node**)malloc(s->size * sizeof(struct Node*));

    struct Node* root = NULL;

    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 76);
    root = insert(root, 28);

    printf("Recursive Inorder: ");
    inorderRecursive(root);

    mirrorImage(root);

    printf("\nMirror Image Inorder (Non-Recursive): ");
    inOrder(root, s);
    
    printf("\nPreorder without recursion:");
    preOrder(root,s);

    printf("\nPostorder without recursion:");
    postOrder(root,s);
    
    return 0;
}

