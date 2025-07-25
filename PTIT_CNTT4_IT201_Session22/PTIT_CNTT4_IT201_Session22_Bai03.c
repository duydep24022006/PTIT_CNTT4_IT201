#include <stdio.h>
#include <stdlib.h>

int** initGraph(int n) {
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(int** graph, int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void printGraph(int** graph, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(int** graph, int n) {
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
}

int main() {
    int n;
    scanf("%d", &n);

    int** graph = initGraph(n);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);

    printGraph(graph, n);

    freeGraph(graph, n);
    return 0;
}