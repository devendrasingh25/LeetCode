class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> bestHealth(m, vector<int>(n, -1));

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        deque<tuple<int,int,int>> q; 
        q.push_back({0, 0, startHealth});
        bestHealth[0][0] = startHealth;

        int dr[] = {0, 1, -1, 0};
        int dc[] = {1, 0, 0, -1};

        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop_front();

            if (h < bestHealth[r][c]) continue; 
            if (r == m-1 && c == n-1) return true; 

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                int nh = h - grid[nr][nc];
                if (nh <= 0) continue;

                if (nh > bestHealth[nr][nc]) {
                    bestHealth[nr][nc] = nh;
                    if (grid[nr][nc] == 0)
                        q.push_front({nr, nc, nh});
                    else
                        q.push_back({nr, nc, nh}); 
                }
            }
        }
        return false;
    }
};