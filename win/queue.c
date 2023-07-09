#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -15;
}

int isEmpty(Queue* queue) {
    return queue->front == -1;
}

int isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue Overflow: Unable to enqueue item %d\n", item);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->data[queue->rear] = item;
        printf("Enqueued item %d\n", item);
    }
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow: Unable to dequeue item\n");
        return -1;
    } else {
        int item = queue->data[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("Dequeued item %d\n", item);
        return item;
    }
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return queue->data[queue->front];
    }
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Elements of the queue: ");
        int i = queue->front;
        while (i != queue->rear) {
            printf("%d ", queue->data[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue->data[i]);
    }
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    int choice, item;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;

            case 2:
                dequeue(&queue);
                break;

            case 3:
                item = peek(&queue);
                if (item != -1) {
                    printf("Front element of the queue: %d\n", item);
                }
                break;

            case 4:
                display(&queue);
                break;

            case 5:
                printf("Exiting the program\n");
                exit(0);

            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }

    return 0;
}
