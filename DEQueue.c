#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct DEQueue {
    int size;
    int front;
    int rear;
    int *arr;
};

bool isEmpty(struct DEQueue *);
bool isFull(struct DEQueue *);
void enqueueFront(struct DEQueue *);
void enqueueRear(struct DEQueue *);
void dequeueFront(struct DEQueue *);
void dequeueRear(struct DEQueue *);
void displayFront(struct DEQueue *);
void displayRear(struct DEQueue *);

int main() {
    struct DEQueue *deque = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    printf("Enter the maximum size of the DEQueue: ");
    scanf("%d", &deque->size);
    deque->arr = (int *)malloc(deque->size * sizeof(int));
    deque->front = -1;
    deque->rear = -1;
    int ch;
    while (1) {
        printf("\n1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display Front\n");
        printf("6. Display Rear\n");
        printf("7. Exit\n");
        printf("Enter your choice of operations: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            enqueueFront(deque);
            break;
        case 2:
            enqueueRear(deque);
            break;
        case 3:
            dequeueFront(deque);
            break;
        case 4:
            dequeueRear(deque);
            break;
        case 5:
            displayFront(deque);
            break;
        case 6:
            displayRear(deque);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Input\n");
            break;
        }
    }
}

bool isEmpty(struct DEQueue *ptr) {
    return ptr->front == -1;
}

bool isFull(struct DEQueue *ptr) {
    return ptr->rear == ptr->size - 1;
}

void enqueueFront(struct DEQueue *ptr) {
    if (isFull(ptr) || ptr->front == 0) {
        printf("Cannot insert at the front (Overflow or front at start)!\n");
    } 
    else {
        int value;
        printf("Enter the value to be inserted at the front: ");
        scanf("%d", &value);
        if (isEmpty(ptr)) {
            ptr->front = ptr->rear = 0;
        } 
        else {
            ptr->front--;
        }
        ptr->arr[ptr->front] = value;
    }
}

void enqueueRear(struct DEQueue *ptr) {
    if (isFull(ptr)) {
        printf("Overflow!\n");
    } 
    else {
        int value;
        printf("Enter the value to be inserted at the rear: ");
        scanf("%d", &value);
        if (isEmpty(ptr)) {
            ptr->front = ptr->rear = 0;
        } 
        else {
            ptr->rear++;
        }
        ptr->arr[ptr->rear] = value;
    }
}

void dequeueFront(struct DEQueue *ptr) {
    if (isEmpty(ptr)) {
        printf("Underflow!\n");
    } 
    else {
        printf("The value removed from the front is: %d\n", ptr->arr[ptr->front]);
        if (ptr->front == ptr->rear) {
            ptr->front = ptr->rear = -1;
        } 
        else {
            ptr->front++;
        }
    }
}

void dequeueRear(struct DEQueue *ptr) {
    if (isEmpty(ptr)) {
        printf("Underflow!\n");
    } 
    else {
        printf("The value removed from the rear is: %d\n", ptr->arr[ptr->rear]);
        if (ptr->front == ptr->rear) {
            ptr->front = ptr->rear = -1;
        } 
        else {
            ptr->rear--;
        }
    }
}

void displayFront(struct DEQueue *ptr) {
    if (!isEmpty(ptr)) {
        printf("The frontmost value is: %d\n", ptr->arr[ptr->front]);
    } 
    else {
        printf("404 NOT FOUND\n");
    }
}

void displayRear(struct DEQueue *ptr) {
    if (!isEmpty(ptr)) {
        printf("The rearmost value is: %d\n", ptr->arr[ptr->rear]);
    } 
    else {
        printf("404 NOT FOUND\n");
    }
}
