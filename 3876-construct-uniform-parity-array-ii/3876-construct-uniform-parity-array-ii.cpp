class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
         long long minOdd = LLONG_MAX, minEven = LLONG_MAX;
        int oddCount = 0;

        for (int x : nums1) {
            if (x % 2 == 1) {
                oddCount++;
                minOdd = min(minOdd, (long long)x);
            } else {
                minEven = min(minEven, (long long)x);
            }
        }

        bool allEvenPossible = (oddCount == 0);

        bool allOddPossible;
        if (minEven == LLONG_MAX) {
            allOddPossible = true;
        } else if (minOdd == LLONG_MAX) {
            allOddPossible = false;
        } else {
            allOddPossible = (minOdd < minEven);
        }

        return allEvenPossible || allOddPossible;
    }
};