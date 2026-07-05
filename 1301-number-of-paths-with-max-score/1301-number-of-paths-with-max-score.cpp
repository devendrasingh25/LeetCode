class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        vector<vector<long long>> ways(n, vector<long long>(n, 0));

        dp[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;

        for (int r = n - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (board[r][c] == 'X') continue;
                if (r == n-1 && c == n-1) continue;

                long long best = -1, cnt = 0;
                int nr[] = {r+1, r, r+1};
                int nc[] = {c, c+1, c+1};

                for (int i = 0; i < 3; i++) {
                    int pr = nr[i], pc = nc[i];
                    if (pr < n && pc < n && dp[pr][pc] != -1) {
                        if (dp[pr][pc] > best) {
                            best = dp[pr][pc];
                            cnt = ways[pr][pc];
                        } else if (dp[pr][pc] == best) {
                            cnt = (cnt + ways[pr][pc]) % MOD;
                        }
                    }
                }

                if (best == -1) continue;

                int cellValue = (board[r][c] == 'E') ? 0 : (board[r][c] - '0');
                dp[r][c] = best + cellValue;
                ways[r][c] = cnt;
            }
        }

        if (dp[0][0] == -1) return {0, 0};
        return {(int)dp[0][0], (int)ways[0][0]};
    }
};