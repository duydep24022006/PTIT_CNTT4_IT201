#include <stdio.h>
#include <stdlib.h>


void addEdge(int** graph, int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)calloc(n, sizeof(int));
    }

    int u, v;
    while (scanf("%d %d", &u, &v) == 2) {
        addEdge(graph, u, v);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
