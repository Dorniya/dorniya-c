#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int front, rear;
    int capacity;
    int* array;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue)
        return NULL;
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (!queue->array)
        return NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

int isFull(struct Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    printf("%d enqueued to the queue\n", item);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->capacity;
    return item;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->array[queue->front];
}

int main() {
    struct Queue* queue = createQueue(MAX_SIZE);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Front element: %d\n", front(queue));

    printf("%d dequeued from the queue\n", dequeue(queue));
    printf("%d dequeued from the queue\n", dequeue(queue));

    printf("Is the queue empty? %s\n", isEmpty(queue) ? "Yes" : "No");

    return 0;
}
