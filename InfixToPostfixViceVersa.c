#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Stack {
    int top;
    int size;
    char *arr;
};

int ifOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^');
}

char stackTop(struct Stack *sp) {
    if (sp->top == -1) return '\0';
    return sp->arr[sp->top];
}

int isEmpty(struct Stack *sp) {
    return (sp->top == -1);
}

int prec(char c) {
    if (c=='+' || c=='-') return 1;
    if (c=='*' || c=='/' || c=='%') return 2;
    if (c=='^') return 3;
    return 0;
}

void push(struct Stack *sp, char data) {
    if (sp->top == sp->size - 1) return;
    sp->arr[++sp->top] = data;
}

char pop(struct Stack *sp) {
    if (isEmpty(sp)) return '\0';
    return sp->arr[sp->top--];
}

char* InfixToPostfix(char *infix) {
    struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = MAX;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    char *postfix = (char*)malloc((strlen(infix) + 1) * sizeof(char));

    int i=0, j=0;
    while (infix[i] != '\0') {
        if (!ifOperator(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            while (!isEmpty(sp) && prec(stackTop(sp)) >= prec(infix[i])) {
                postfix[j++] = pop(sp);
            }
            push(sp, infix[i++]);
        }
    }

    while (!isEmpty(sp))
        postfix[j++] = pop(sp);

    postfix[j] = '\0';
    return postfix;
}

struct StackStr {
    int top;
    char *arr[MAX];
};

void pushStr(struct StackStr *s, char *str) {
    s->arr[++s->top] = str;
}

char* popStr(struct StackStr *s) {
    return s->arr[s->top--];
}

char* PostfixToInfix(char *postfix) {
    struct StackStr s;
    s.top = -1;

    for (int i=0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (!ifOperator(ch)) {
            char *op = (char*)malloc(2);
            op[0] = ch;
            op[1] = '\0';
            pushStr(&s, op);
        } else {
            char *op2 = popStr(&s);
            char *op1 = popStr(&s);

            char *expr = (char*)malloc(strlen(op1)+strlen(op2)+4);
            sprintf(expr, "(%s%c%s)", op1, ch, op2);
            pushStr(&s, expr);
        }
    }
    return popStr(&s);
}

struct StackInt {
    int top;
    int arr[MAX];
};

void pushInt(struct StackInt *s, int val) {
    s->arr[++s->top] = val;
}

int popInt(struct StackInt *s) {
    return s->arr[s->top--];
}

int power(int a, int b) {
    int r = 1;
    while (b--) r *= a;
    return r;
}

int evaluatePostfix(char *postfix) {
    struct StackInt s;
    s.top = -1;

    for (int i=0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (!ifOperator(ch)) {
            pushInt(&s, ch - '0');
        } else {
            int b = popInt(&s);
            int a = popInt(&s);

            if (ch == '+') pushInt(&s, a + b);
            else if (ch == '-') pushInt(&s, a - b);
            else if (ch == '*') pushInt(&s, a * b);
            else if (ch == '/') pushInt(&s, a / b);
            else if (ch == '%') pushInt(&s, a % b);
            else if (ch == '^') pushInt(&s, power(a, b));
        }
    }
    return popInt(&s);
}

int main() {
    char infix[MAX];

    printf("Enter INFIX Expression: ");
    scanf("%s", infix);

    char *postfix = InfixToPostfix(infix);
    printf("Postfix Expression: %s\n", postfix);

    char *newInfix = PostfixToInfix(postfix);
    printf("Infix from Postfix: %s\n", newInfix);

    int result = evaluatePostfix(postfix);
    printf("Postfix Evaluation Result: %d\n", result);

    return 0;
}

