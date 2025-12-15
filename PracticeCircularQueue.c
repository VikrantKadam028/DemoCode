#include<stdio.h>
#include<stdlib.h>

struct CircularQueue{
	int size;
	int front;
	int rear;
	int *arr;
};

int isEmpty(struct CircularQueue* q){
	if(q->front == q->rear){
		return 1;
	}
	return 0;
}

int isFull(struct CircularQueue *q){
	if((q->rear+1)%q->size == q->front){
		return 1;
	}else{
		return 0;
	}
}

void enqueue(struct CircularQueue *q, int val){
	if(isFull(q)){
		printf("Queue Overflow!");
		return;
	}
	else {
		q->rear = (q->rear+1)%q->size;
		q->arr[q->rear] = val;
	}
}

int dequeue(struct CircularQueue *q){
	int val = -1;
	if(isEmpty(q)){
		printf("Queue Underflow!");
		return -1;
	}else{
		q->front = (q->front+1)%q->size;
		val = q->arr[q->front];
	}
	return val;
}

int peek(struct CircularQueue *q){
	if(isEmpty(q)){
		return -1;
	}else {
		return q->arr[(q->front+1)%q->size];
	}
}

void displayQueue(struct CircularQueue *q){
	if(isEmpty(q)){
		return;
	}else {
		printf("\nQueue Elements:");
		int i = (q->front+1)%q->size;
		while(i!=(q->rear+1)%q->size){
			printf("%d ",q->arr[i]);
			i = (i+1)%q->size;
		}
	}
}

int main(){
	struct CircularQueue *q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
	q->size = 10;
	q->front = q->rear = -1;
	q->arr = (int*)malloc(q->size * sizeof(int));
	
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	
	displayQueue(q);
	
	printf("\nDequeued element:%d", dequeue(q));
	displayQueue(q);
	
	printf("\nPeek element:%d",peek(q));
	
	return 0;
}
