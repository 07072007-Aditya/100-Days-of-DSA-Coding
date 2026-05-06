/*
Implement a Min Heap using an array where the smallest element is always at the root.
*/
#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify upward after insertion
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Heapify downward after extraction
void heapifyDown(int index) {
    int smallest = index;

    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

// Insert element
void insert(int value) {
    if (size == MAX) {
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;
}

// Extract minimum element
void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

// Peek minimum element
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char op[20];
        int x;

        scanf("%s", op);

        if (op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'e') {
            extractMin();
        }
        else if (op[0] == 'p') {
            peek();
        }
    }

    return 0;
}