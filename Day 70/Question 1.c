/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, struct Edge edges[], int src) {
    long dist[n + 1];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%ld ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n = 5, m = 8;
    struct Edge edges[] = {
        {1, 2, -1}, {1, 3, 4}, {2, 3, 3}, {2, 4, 2}, 
        {2, 5, 2}, {4, 3, 5}, {4, 2, 1}, {5, 4, -3}
    };

    bellmanFord(n, m, edges, 1);
    return 0;
}
