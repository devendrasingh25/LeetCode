#include<bits/stdc++.h>
using namespace std;
 class Solution {
public:
    int smallestAllOnes(int n) {
        int x = 1;
        while (x < n) {
            x = (x << 1) | 1; // shift left and set all lower bits to 1
        }
        return x;
    }
};
