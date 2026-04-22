/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    cin >> source;

    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == INT_MAX ? -1 : dist[i]) << (i == n ? "" : " ");
    }
    cout << endl;
}

int main() {
    dijkstra();
    return 0;
}
