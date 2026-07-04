class Solution {
public:
    int timer;
    vector<int> dt, low;

    void dfs(int u, int par, vector<vector<int>>& adj, vector<vector<int>>& cc) {
        dt[u] = low[u] = ++timer;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];

            if (dt[v] == -1) {
                dfs(v, u, adj, cc);
                low[u] = min(low[u], low[v]);

                if (low[v] > dt[u]) {
                    cc.push_back({u, v});
                }
            }
            else if (v != par) {
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<vector<int>> adj(n);

        for (auto it : c) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        timer = 0;
        dt.assign(n, -1);
        low.resize(n);

        vector<vector<int>> cc;

        for (int i = 0; i < n; i++) {
            if (dt[i] == -1) {
                dfs(i, -1, adj, cc);
            }
        }

        return cc;
    }
};