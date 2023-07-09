#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow: Unable to push item %d\n", item);
    } else {
        stack->data[++stack->top] = item;
        printf("Pushed item %d\n", item);
    }
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Unable to pop item\n");
        return -1;
    } else {
        int item = stack->data[stack->top--];
        printf("Popped item %d\n", item);
        return item;
    }
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->data[stack->top];
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);

    int choice, item;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(&stack, item);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                item = peek(&stack);
                if (item != -1) {
                    printf("Top element of the stack: %d\n", item);
                }
                break;

            case 4:
                printf("Exiting the program\n");
                exit(0);

            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }

    return 0;
}
