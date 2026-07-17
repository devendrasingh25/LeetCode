class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> cnt(mx + 1, 0);
        for (int x : nums) cnt[x]++;
        for (int d = 1; d <= mx; d++) {
            for (int multiple = 2 * d; multiple <= mx; multiple += d) {
                cnt[d] += cnt[multiple];
            }
        }

        vector<long long> exactPairs(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            long long c = cnt[d];
            exactPairs[d] = c * (c - 1) / 2;
        }

        for (int d = mx; d >= 1; d--) {
            for (int multiple = 2 * d; multiple <= mx; multiple += d) {
                exactPairs[d] -= exactPairs[multiple];
            }
        }

        vector<long long> prefix(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            prefix[d] = prefix[d - 1] + exactPairs[d];
        }

        vector<int> ans;
        for (long long q : queries) {
            int lo = 1, hi = mx;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (prefix[mid] > q) hi = mid;
                else lo = mid + 1;
            }
            ans.push_back(lo);
        }
        return ans;
    }
};