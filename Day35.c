/*
Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.
*/
#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("Queue Overflow");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
}

void display()
{
    int i;

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{
    int n, i, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter queue elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(value);
    }

    display();

    return 0;
}