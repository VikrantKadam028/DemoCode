#include<stdio.h>
#define SIZE 11
#define MAX_KICKS 10

int tableA[SIZE];
int tableB[SIZE];

void init(){
	int i;
	for(i=0;i<SIZE;i++){
		tableA[i] = -1;
		tableB[i] = -1;
	}
}

int h1(int key){
	return key%SIZE;
}

int h2(int key){
	return (key/SIZE)%SIZE;
}

void insert(int key){
	int curr = key;
	int index;
	int inTableA = 1;
	int i;
	for(i=0;i<MAX_KICKS;i++){
	if(inTableA){
			index = h1(curr);
			
			if(tableA[index] == -1){
				tableA[index] = curr;
				return;
			}
		
		int temp = tableA[index];
		tableA[index] = curr;
		curr = temp;
		inTableA = 0;
	} else {
		index = h2(curr);
		if(tableB[index] == -1){
			tableB[index] = curr;
			return;
		}
		
		int temp = tableB[index];
		tableB[index] = curr;
		curr = temp;
		inTableA = 1;
	}
}
}

void display(){
	int i;
	printf("\nTable A Data:");
	for(i = 0 ;i<SIZE;i++){
		printf("\n%d - > %d",i,tableA[i]);
	}
	
	printf("\nTable B Data:");
	for(i = 0 ;i<SIZE;i++){
		printf("\n%d - > %d",i,tableB[i]);
	}
}

int main(){
	init();
	int i;
	int keys[] = {10,33,56,22};
	for(i=0;i<4;i++){
		insert(keys[i]);
	}
	display();
	return 0;
}
