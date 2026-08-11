class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1) {
                prefix += nums[i];
            } else {
                break; 
            }
        }

        unordered_set<int> numSet(nums.begin(), nums.end());
        while (numSet.count(prefix)) {
            prefix++;
        }
        return prefix;
    }
};