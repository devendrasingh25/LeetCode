class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0;
        for (int x : nums1) {
            if (x % 2 != 0) odd++;
        }
        bool allEvenPossible = (odd == 0) || (odd >= 2);
        bool allOddPossible  = (odd >= 1);
        return allEvenPossible || allOddPossible;
    }
};