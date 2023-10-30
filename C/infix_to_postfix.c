#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i, j;
    j = 0;

    for (i = 0; infix[i]; i++) {
        char token = infix[i];
        if (token >= '0' && token <= '9') {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                printf("Invalid expression\n");
                exit(1);
            } else {
                pop(&stack);
            }
        } else {
            while (!isEmpty(&stack) && getPrecedence(token) <= getPrecedence(stack.items[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
