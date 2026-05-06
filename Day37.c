/*
Implement a Priority Queue using an array. An element with smaller value has higher priority.
*/

#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;


void insert(int value) {
    if (size == MAX) {
        printf("Priority Queue Overflow\n");
        return;
    }

    int i = size - 1;

    
    while (i >= 0 && pq[i] > value) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    size++;

    printf("%d inserted\n", value);
}


void delete() {
    if (size == 0) {
        printf("Priority Queue Underflow\n");
        return;
    }

    printf("%d deleted\n", pq[0]);

    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}


void peek() {
    if (size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Top priority element = %d\n", pq[0]);
}


void display() {
    if (size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Insert 2.Delete 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}