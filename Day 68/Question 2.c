/*A classic application of Topological Sort. To solve it, we treat each unique character as 
a node in a graph and the relative ordering between characters as directed edges.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        for (const string& word : words) {
            for (char c : word) {
                if (inDegree.find(c) == inDegree.end()) {
                    inDegree[c] = 0;
                }
            }
        }

        for (int i = 0; i < (int)words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min((int)w1.length(), (int)w2.length());
            bool foundDifference = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
                        adj[w1[j]].insert(w2[j]);
                        inDegree[w2[j]]++;
                    }
                    foundDifference = true;
                    break;
                }
            }
            if (!foundDifference && w1.length() > w2.length()) return "";
        }

        queue<char> q;
        for (auto const& [ch, degree] : inDegree) {
            if (degree == 0) q.push(ch);
        }

        string result = "";
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            result += u;

            if (adj.count(u)) {
                for (char v : adj[u]) {
                    inDegree[v]--;
                    if (inDegree[v] == 0) q.push(v);
                }
            }
        }

        return (result.length() == inDegree.size()) ? result : "";
    }
};
