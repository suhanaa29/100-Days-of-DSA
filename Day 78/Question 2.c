/*To find all Articulation Points (also known as cut vertices) in an undirected graph.*/

class Solution {
  public:
    void dfs(int u, int p, int &timer, vector<int> &disc, vector<int> &low, 
             vector<bool> &isArticulation, vector<int> adj[]) {
        
        disc[u] = low[u] = ++timer;
        int children = 0;

        for (auto v : adj[u]) {
            if (v == p) continue;
            
            if (disc[v] == 0) {
                children++;
                dfs(v, u, timer, disc, low, isArticulation, adj);
                low[u] = min(low[u], low[v]);
                
                if (p != -1 && low[v] >= disc[u]) {
                    isArticulation[u] = true;
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
        
        if (p == -1 && children > 1) {
            isArticulation[u] = true;
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, 0), low(V, 0);
        vector<bool> isArticulation(V, false);
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (disc[i] == 0) {
                dfs(i, -1, timer, disc, low, isArticulation, adj);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (isArticulation[i]) result.push_back(i);
        }

        if (result.empty()) return {-1};
        return result;
    }
};
