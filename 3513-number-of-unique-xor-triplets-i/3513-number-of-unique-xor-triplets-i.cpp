class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;

        int highest = 1 << (31 - __builtin_clz(n)); 
        return highest << 1;
    }
};