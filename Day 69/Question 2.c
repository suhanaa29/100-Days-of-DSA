/*We will send a signal from a given node k.
Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1*/

#include <limits.h>
#include <stdbool.h>

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int dist[n + 1];
    bool visited[n + 1];
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    
    dist[k] = 0;
    
    for (int i = 0; i < n; i++) {
        int u = -1;
        int minDist = INT_MAX;
        
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        
        if (u == -1) break;
        visited[u] = true;
        
        for (int j = 0; j < timesSize; j++) {
            if (times[j][0] == u) {
                int v = times[j][1];
                int w = times[j][2];
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        if (dist[i] > maxTime) maxTime = dist[i];
    }
    
    return maxTime;
}
