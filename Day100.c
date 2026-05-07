/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val, idx;
} Node;

void merge(Node arr[], int left, int mid, int right, int count[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Node *L = (Node *)malloc(n1 * sizeof(Node));
    Node *R = (Node *)malloc(n2 * sizeof(Node));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left, rightCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            count[L[i].idx] += rightCount;
            arr[k++] = L[i++];
        } else {
            rightCount++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        count[L[i].idx] += rightCount;
        arr[k++] = L[i++];
    }

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(Node arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], count[n];
    Node nodes[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        nodes[i].val = arr[i];
        nodes[i].idx = i;
        count[i] = 0;
    }

    mergeSort(nodes, 0, n - 1, count);

    printf("Counts:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    return 0;
}