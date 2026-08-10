class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s * s <= i; s++) {
                if (!dp[i - s * s]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};