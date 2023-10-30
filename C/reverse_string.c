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

int main() {
    char input[MAX_SIZE];
    char reversed[MAX_SIZE];
    struct Stack stack;

    initialize(&stack);

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);
    input[strlen(input) - 1] = '\0'; // Remove the newline character

    // Push each character of the input string onto the stack
    for (int i = 0; input[i] != '\0'; i++) {
        push(&stack, input[i]);
    }

    // Pop the characters from the stack to create the reversed string
    int i = 0;
    while (!isEmpty(&stack)) {
        reversed[i++] = pop(&stack);
    }
    reversed[i] = '\0';

    printf("Reversed string: %s\n", reversed);

    return 0;
}
