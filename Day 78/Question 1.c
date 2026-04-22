/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm*/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_V 100
#define INF INT_MAX

int getMinVertex(int key[], bool inMST[], int n) {
    int min = INF, min_idx = -1;
    for (int v = 1; v <= n; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v], min_idx = v;
        }
    }
    return min_idx;
}

int main() {
    int n, m;
    int graph[MAX_V][MAX_V] = {0};
    int key[MAX_V];
    bool inMST[MAX_V] = {false};

    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (graph[u][v] == 0 || w < graph[u][v]) {
            graph[u][v] = graph[v][u] = w;
        }
    }

    for (int i = 1; i <= n; i++) key[i] = INF;

    key[1] = 0;
    int total_weight = 0;

    for (int count = 0; count < n; count++) {
        int u = getMinVertex(key, inMST, n);
        if (u == -1) break;

        inMST[u] = true;
        total_weight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total_weight);
    return 0;
}
