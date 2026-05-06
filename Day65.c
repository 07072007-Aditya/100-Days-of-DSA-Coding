/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];    // Visited array
int n;               // Number of vertices

// DFS function to detect cycle
int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {  // If edge exists
            if (!visited[i]) {
                if (dfs(i, node)) {
                    return 1; // Cycle found
                }
            }
            else if (i != parent) {
                return 1; // Cycle detected
            }
        }
    }
    return 0;
}

int hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int m, u, v;

    // Input number of vertices and edges
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    // Check cycle
    if (hasCycle()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}