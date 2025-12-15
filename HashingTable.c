#include<stdio.h>
#define SIZE 11

int table[SIZE];

void init(){
	int i;
  for(i=0;i<SIZE;i++){
    table[i] = -1;
  }
}

void insert(int key, int step){
  int index = key % SIZE;
  
  //collision
  int i;
  for(i=0;i<SIZE;i++){
    int newIndex = (index + i * step) % SIZE;
    
    if(table[newIndex] == -1){
      table[newIndex] = key;
      return;
    }
  }
  printf("\nTable is full!");
}

void display(){
	int i;
  for(i=0;i<SIZE;i++){
    printf("%d -> %d\n",i,table[i]);
  }
}


int main(){
  init();
  
  int step = 3;
  int keys[] = {22,33,44};
  int i;
  for(i=0;i<3;i++){
    insert(keys[i],step);
  }
  
  display();
  
  return 0;
}
