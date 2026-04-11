/*You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops.
If there is no such route, return -1*/

#include <limits.h>
#include <string.h>

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i <= k; i++) {
        int temp[n];
        memcpy(temp, dist, sizeof(int) * n);
        
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];
            
            if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }
        memcpy(dist, temp, sizeof(int) * n);
    }

    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}
