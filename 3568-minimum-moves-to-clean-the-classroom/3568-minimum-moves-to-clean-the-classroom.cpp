class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        vector<pair<int,int>> litter;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        if (k == 0) return 0;

        vector<vector<int>> id(m, vector<int>(n, -1));
        for (int i = 0; i < k; i++) {
            auto [r, c] = litter[i];
            id[r][c] = i;
        }

        int fullMask = (1 << k) - 1;
        int numMasks = 1 << k;
        int eCount = energy + 1;

        struct State {
            int r, c, mask, energy;
        };

       
        vector<bool> visited((size_t)m * n * numMasks * eCount, false);

        auto idx = [&](int r, int c, int mask, int e) -> size_t {
            return (((size_t)r * n + c) * numMasks + mask) * eCount + e;
        };

        queue<State> q;
        q.push({sr, sc, 0, energy});
        visited[idx(sr, sc, 0, energy)] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                State cur = q.front();
                q.pop();

                int r = cur.r, c = cur.c, mask = cur.mask, e = cur.energy;

                if (mask == fullMask)
                    return moves;

                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = e - 1;
                    int newMask = mask;

                    if (classroom[nr][nc] == 'L') {
                        int litterIdx = id[nr][nc];
                        newMask |= (1 << litterIdx);
                    }

                    if (classroom[nr][nc] == 'R')
                        newEnergy = energy;

                    size_t key = idx(nr, nc, newMask, newEnergy);
                    if (!visited[key]) {
                        visited[key] = true;
                        q.push({nr, nc, newMask, newEnergy});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};