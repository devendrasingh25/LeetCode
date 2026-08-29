class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> indexed(n);
        iota(indexed.begin(), indexed.end(), 0);
        sort(indexed.begin(), indexed.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[indexed[j + 1]] - nums[indexed[j]] <= limit) {
                j++;
            }

            vector<int> groupIndices(indexed.begin() + i, indexed.begin() + j + 1);
            sort(groupIndices.begin(), groupIndices.end());

            for (int k = 0; k < (int)groupIndices.size(); k++) {
                result[groupIndices[k]] = nums[indexed[i + k]];
            }

            i = j + 1;
        }

        return result;
    }
};