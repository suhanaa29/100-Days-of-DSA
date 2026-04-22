/*find the number of Strongly Connected Components (SCCs) in a directed graph.*/

class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) dfs(v, adj, vis, st);
        }
        st.push(u);
    }

    void revDfs(int u, vector<vector<int>>& adjRev, vector<bool>& vis) {
        vis[u] = true;
        for (int v : adjRev[u]) {
            if (!vis[v]) revDfs(v, adjRev, vis);
        }
    }

    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> st;
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        vector<vector<int>> adjRev(V);
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                adjRev[neighbor].push_back(i);
            }
        }

        fill(vis.begin(), vis.end(), false);
        int sccCount = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (!vis[u]) {
                sccCount++;
                revDfs(u, adjRev, vis);
            }
        }

        return sccCount;
    }
};
