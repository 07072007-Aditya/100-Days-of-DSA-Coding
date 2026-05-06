/*
Problem: Deque (Double-Ended Queue)
*/
#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Insert at front
void push_front(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = value;
}

// Insert at rear
void push_back(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
}

// Delete from front
void pop_front() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }

    printf("%d removed from front\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// Delete from rear
void pop_back() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }

    printf("%d removed from rear\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

// Front element
void get_front() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Front = %d\n", deque[front]);
}

// Rear element
void get_back() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Rear = %d\n", deque[rear]);
}

// Empty check
void empty() {
    if (front == -1)
        printf("Deque is empty\n");
    else
        printf("Deque is not empty\n");
}

// Size
void size() {
    if (front == -1) {
        printf("Size = 0\n");
        return;
    }

    if (rear >= front)
        printf("Size = %d\n", rear - front + 1);
    else
        printf("Size = %d\n", MAX - front + rear + 1);
}

// Display deque
void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;

    printf("Deque: ");

    while (1) {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);

    display();

    pop_front();
    display();

    pop_back();
    display();

    get_front();
    get_back();

    empty();
    size();

    return 0;
}