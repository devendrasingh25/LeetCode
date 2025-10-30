#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        long long low = 1, high = x, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long sq = mid * mid;

            if (sq == x)
                return mid;               // perfect square found
            else if (sq < x) {
                ans = mid;                // store potential answer
                low = mid + 1;            // move right
            } else {
                high = mid - 1;           // move left
            }
        }

        return ans; // floor of sqrt(x)
    }
};
