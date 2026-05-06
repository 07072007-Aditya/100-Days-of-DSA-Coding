/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/
/*
Problem: Dijkstra's Algorithm using Priority Queue
- Input: Weighted graph (adjacency matrix)
- Output: Shortest distance from source to all vertices
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

int n;

// Function to find the node with minimum distance (acts like priority queue)
int extractMin(int dist[], int visited[]) {
    int min = INT_MAX, index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[MAX][MAX], int source) {
    int dist[MAX];
    int visited[MAX] = {0};

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = extractMin(dist, visited);

        if (u == -1) break;

        visited[u] = 1;

        // Update neighbors
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int graph[MAX][MAX], source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source);

    return 0;
}