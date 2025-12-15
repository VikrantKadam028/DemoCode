#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int data){
	struct Node* newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

struct Node* insertAtFirst(struct Node* head, int data){
	struct Node* newNode = createNode(data);
	newNode->next = head;
	head = newNode;
	return head;
}

struct Node* insertAtMiddle(struct Node* head, int pos, int data){
	int count = 1;
	struct Node* temp = head;
	struct Node* newNode = createNode(data);
	
	while(count < pos-1){
		count ++;
		temp = temp->next;
	}
	
	newNode->next = temp->next;
	temp->next = newNode;
	return head;
}

struct Node* insertAtEnd(struct Node* head, int data){
	struct Node* temp = head;
	struct Node* newNode = createNode(data);
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->next = NULL;
	return head;
}

struct Node* deleteAtFirst(struct Node* head){
	struct Node* temp = head;
	head =  head->next;
	free(temp);
	return head;
}

struct Node* deleteAtMiddle(struct Node* head, int pos){
    int count = 1;
    struct Node* temp = head;

    if(pos == 1){
        head = head->next;
        free(temp);
        return head;
    }

    while(count < pos - 1 && temp->next != NULL){
        temp = temp->next;
        count++;
    }

    if(temp->next != NULL){
        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }

    return head;
}

struct Node* deleteAtEnd(struct Node* head){
	struct Node* temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
	return head;
}

void displayLL(struct Node* head){
	struct Node* temp;
	temp = head;
	
	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL");
}

int main(){
	struct Node* head = createNode(10);
	struct Node* first = createNode(20);
	struct Node* second = createNode(30);
	struct Node* third = createNode(40);
	
	head->next = first;
	first->next = second;
	second->next = third;
	third->next = NULL;
	displayLL(head);
	
	head = insertAtFirst(head, 0);
	printf("\nINSERT AT FIRST :\n");
	displayLL(head);
	
	head = insertAtMiddle(head, 3, 100);
	printf("\nINSERT AT MIDDLE :\n");
	displayLL(head);
	
	head = insertAtEnd(head,50);
	printf("\nINSERT AT END :\n");
	displayLL(head);
	
	head = deleteAtFirst(head);
	printf("\nDELETE AT FIRST :\n");
	displayLL(head);
	
	head = deleteAtEnd(head);
	printf("\nDELETE AT END :\n");
	displayLL(head);
	
	head = deleteAtMiddle(head, 2);
	printf("\nDELETE AT MIDDLE :\n");
	displayLL(head);
	
	return 0;
}
