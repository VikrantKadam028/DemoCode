#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node* createNode(int data){
	struct Node* newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

struct Node* insertAtFirst(struct Node* head, int data){
	struct Node* newNode = createNode(data);
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	newNode->prev = NULL;
	return head;
}

struct Node* insertAtMiddle(struct Node* head, int data,int pos){
	int count= 1;
	struct Node* temp = head;
	
	while(count < pos-1){
		count++;
		temp = temp->next;
	}
	
	struct Node* NN = createNode(data);
	temp->next->prev = NN;
	NN->next = temp->next;
	temp->next = NN;
	NN->prev = temp;
	return head;
}

struct Node* insertAtEnd(struct Node* head, int data){
	struct Node* temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	struct Node* NN = createNode(data);
	
	temp->next = NN;
	NN->prev = temp;
	NN->next = NULL;
	return head;
}

void displayLL(struct Node* head){
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d <-> ",temp->data);
		temp = temp->next;
	}
	printf("NULL");
}

void displayEven(struct Node* head){
	struct Node* temp = head;
	
	while(temp != NULL){
		if(temp->data % 2 == 0){
			printf("%d <-> ", temp->data);
		}
		temp = temp->next;
	}
}

struct Node* swapFirstLast(struct Node* head){
	if(head == NULL || head->next == NULL) return head;
	
	struct Node* first = head;
	struct Node* last = head;
	
	while(last->next != NULL){
		last = last->next;
	}
	
	struct Node* second = first->next;
	struct Node* secondlast = last->prev;
	
	first->next = NULL;
	last->prev = NULL;
	
	second->prev = last;
	last->next = second;
	
	secondlast->next = first;
	first->prev = secondlast;
	
	return last;
}

int main(){
	struct Node* head = createNode(10);
	struct Node* first = createNode(20);
	struct Node* second = createNode(30);
	struct Node* third = createNode(40);
	
	head->prev = NULL;
	head->next = first;
	first->prev = head;
	first->next = second;
	second->prev = first;
	second->next = third;
	third->prev = second;
	third->next = NULL;
	
	displayLL(head);
	
	head = insertAtFirst(head,5);
	printf("\nLL after insert at beginning:\n");
	displayLL(head);
	
	head = insertAtMiddle(head,100,2);
	printf("\nLL after insert at pos:\n");
	displayLL(head);
	
	head = insertAtEnd(head,50);
	printf("\nLL after insert at end:\n");
	displayLL(head);
	
	printf("\nLL even:\n");
	displayEven(head);	
	
	head = swapFirstLast(head);
	printf("\nLL after swapping first and last:\n");
	displayLL(head);
	return 0;
}
