/*
Given a queue of integers, reverse the queue using a stack.
*/
#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int front = 0, rear = -1;
int top = -1;

// Enqueue
void enqueue(int value) {
    queue[++rear] = value;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Push into stack
void push(int value) {
    stack[++top] = value;
}

// Pop from stack
int pop() {
    return stack[top--];
}

int main() {
    int N;
    scanf("%d", &N);

    // Input queue elements
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Move queue to stack
    while (front <= rear) {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Move stack back to queue
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}