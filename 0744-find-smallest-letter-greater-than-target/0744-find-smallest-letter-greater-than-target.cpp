class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size() - 1;
        int ans = 0;   

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (letters[mid] > target) {
                ans = mid;
                hi = mid - 1;  
            } else {
                lo = mid + 1;
            }
        }

        return letters[lo % letters.size()];
    }
};