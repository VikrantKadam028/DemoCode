#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct Stack{
	int size;
	int top;
	char *arr;
};

int isFull(struct Stack *s){
	return s->top == s->size - 1;
}

int isEmpty(struct Stack *s){
	return s->top == -1;
}

void push(struct Stack *s, char data){
	if(isFull(s)){
		printf("Stack is Full!");
		return;
	}
	s->top++;
	s->arr[s->top] = data;
}

char pop(struct Stack *s){
	if(isEmpty(s)){
		printf("\nStack underflow!");
		return -1;
	}
	char elem = s->arr[s->top];
	s->top--;
	return elem;
}

int isMatchPair(char open, char close){
	return (
	(open == '(' && close == ')') ||
	(open == '[' && close == ']') ||
	(open == '{' && close == '}')
	);
}

int ParenthesisMatch(char* exp){
	struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack));
	sp->size = MAX;
	sp->top = -1;
	sp->arr = (char*)malloc(sp->size * sizeof(char));
	
	int i;
//	char popped;
	
	for(i = 0;exp[i] != '\0';i++){
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
			push(sp, exp[i]);
		}else {
			if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
				if(isEmpty(sp)) return 0;
				
				if(isMatchPair(sp->arr[sp->top],exp[i])){
					pop(sp);
				}else {
					return 0;
				}
			}
		}
	}
	return isEmpty(sp);
}

int main(){
	char exp[MAX];
	printf("\nEnter the exp:");
	scanf("%s",&exp);
	
	if(ParenthesisMatch(exp)){
		printf("\nExpression is Balanced!");
	}else{
		printf("\nExpression is not Balanced!");
	}
	return 0;
}

