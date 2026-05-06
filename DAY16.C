#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++) {
        int count = 1;
        int visited = 0;

        for(int k = 0; k < i; k++) {
            if(arr[i] == arr[k]) {
                visited = 1;
                break;
            }
        }

        if(visited) continue;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}
