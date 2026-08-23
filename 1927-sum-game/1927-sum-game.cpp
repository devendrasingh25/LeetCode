class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int lsk = 0, rsk = 0, lc = 0, rc = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2) lc++;
                else rc++;
            } else {
                if (i < n / 2) lsk += num[i] - '0';
                else rsk += num[i] - '0';
            }
        }
        if ((lc + rc) % 2 != 0) return true;
        int left = 2 * lsk + 9 * lc;
        int right = 2 * rsk + 9 * rc;
        return left != right;
    }
};