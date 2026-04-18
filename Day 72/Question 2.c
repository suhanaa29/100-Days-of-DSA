/*TRAVELLING SALESMAN PROBLEM*/

#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int dp[1 << 15][15];

    int solve(int mask, int pos, int n, vector<vector<int>>& cost) {
        if (mask == (1 << n) - 1) {
            return cost[pos][0];
        }

        if (dp[mask][pos] != -1) {
            return dp[mask][pos];
        }

        int ans = 1e9;

        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                int newAns = cost[pos][city] + solve(mask | (1 << city), city, n, cost);
                ans = min(ans, newAns);
            }
        }

        return dp[mask][pos] = ans;
    }

    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, n, cost);
    }
};
