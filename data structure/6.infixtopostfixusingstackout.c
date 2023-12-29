#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack)
        return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    if (!stack->array)
        return NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

void infixToPostfix(char* infix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, k;

    for (i = 0, k = -1; infix[i]; ++i) {
        if (isOperand(infix[i]))
            infix[++k] = infix[i];
        else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                infix[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else
                pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                infix[++k] = pop(stack);
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack))
        infix[++k] = pop(stack);

    infix[++k] = '\0';
    printf("Postfix expression: %s\n", infix);
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
