/*
Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
*/

#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;


void enqueue(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)   
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
}


void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear)   
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}


void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }
}

int main()
{
    int n, m, i, value;

    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(value);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {
        dequeue();
    }

    printf("Queue elements after operations: ");
    display();

    return 0;
}