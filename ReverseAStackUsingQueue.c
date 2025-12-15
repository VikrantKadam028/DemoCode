#include<stdio.h>
#include<stdlib.h>

struct Stack{
	int size;
	int top;
	int* arr;
};

struct Queue{
	int size;
	int front;
	int rear;
	int *arr;
};

// Stack
int isFullStack(struct Stack *s){
	if(s->top == s->size-1){
		return 1;
	}
	return 0;
}

int isEmptyStack(struct Stack *s){
	if(s->top == -1){
		return 1;
	}else {
		return 0;
	}
}

void push(struct Stack *s, int val){
	if(isFullStack(s)){
		return;
	}else {
		s->top++;
		s->arr[s->top] = val;
	}
}

int pop(struct Stack *s){
	if(isEmptyStack(s)){
		return -1;
	}else {
		int val = s->arr[s->top];
		s->top--;
		return val;
	}
}

// Queue
int isFullQueue(struct Queue *q){
	if(q->rear == q->size-1){
		return 1;
	}
	return 0;
}

int isEmptyQueue(struct Queue *q){
	if(q->front == -1 || q->front > q->rear){ // mistake 2
		return 1;
	}
	return 0;
}

void enqueue(struct Queue *q, int val){
	if(isFullQueue(q)){
		return;
	}else {
		if(q->front == -1) q->front = 0; // mistake 1
		q->rear++;
		q->arr[q->rear] = val;
	}
}

int dequeue(struct Queue *q){
	if(isEmptyQueue(q)){
		return -1;
	}
	else {
		int val = q->arr[q->front];
		q->front ++;
		return val;
	}
}

void displayStack(struct Stack *s){
	int i=0;
	if(isEmptyStack(s)){
		return;
	}else {
		for(i =s->top;i>=0;i--){
			printf("%d ",s->arr[i]);
		}
	}
}

int main(){
	struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
	s->size = 10;
	s->top = -1;
	s->arr = (int*)malloc(s->size * sizeof(int));
	
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	q->size = 10;
	q->front = q->rear = -1;
	q->arr = (int*)malloc(q->size * sizeof(int));
	
	
	push(s,10);
	push(s,20);
	push(s,30);
	printf("\nOG Stack:");
	displayStack(s);
	
	int elem;
	while(s->top != -1){
		elem = pop(s);
		enqueue(q,elem);
	}
	
	while(q->front <= q->rear){
		push(s, dequeue(q));
	}
	printf("\nReversed Stack:");
	displayStack(s);
	return 0;
}
