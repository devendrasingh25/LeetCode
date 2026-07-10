class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
       
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> val(n), pos(n);
        for (int i = 0; i < n; i++) {
            val[i] = nums[order[i]];
            pos[order[i]] = i;
        }

       
        vector<int> R(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < i) j = i;
            while (j + 1 < n && val[j + 1] - val[i] <= maxDiff) j++;
            R[i] = j;
        }

        
        int LOG = max(1, (int)floor(log2(max(2, n))) + 1);
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = R;
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        auto dist = [&](int l, int r) -> int {
            if (l == r) return 0;
            if (l > r) swap(l, r);
            if (R[l] >= r) return 1;
            int cur = l, steps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                int nxt = up[k][cur];
                if (nxt < r) {
                    cur = nxt;
                    steps += (1 << k);
                }
            }
            if (R[cur] < r) return -1;
            return steps + 1;
        };

        int q = queries.size();
        vector<int> answer(q);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0], v = queries[i][1];
            answer[i] = dist(pos[u], pos[v]);
        }
        return answer;
    }
};