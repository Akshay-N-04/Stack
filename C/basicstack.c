
/*Design, develop and execute a program in C to simulate the working of
a stack of integers using an array. Provide the following operations: 
(a) Push 
(b) Pop 
(c) Display. */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8

int s[MAX_SIZE], top = -1;

void push() {
    int x;
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);
    top = top + 1;
    s[top] = x;
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    printf("Popped element is %d\n", s[top]);
    top = top - 1;
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    } else {
        printf("Contents of the stack:\n");
        for (i = 0; i <= top; i++) {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch, x;
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    for (;;) {
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
