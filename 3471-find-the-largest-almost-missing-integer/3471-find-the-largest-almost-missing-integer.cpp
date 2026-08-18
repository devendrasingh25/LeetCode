class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        
        for (int i = 0; i + k <= n; i++) {
            unordered_set<int> present;
            for (int j = i; j < i + k; j++) {
                present.insert(nums[j]);
            }
            for (int v : present) {
                count[v]++;
            }
        }
        
        int result = -1;
        for (auto& [val, cnt] : count) {
            if (cnt == 1) {
                result = max(result, val);
            }
        }
        
        return result;
    }
};