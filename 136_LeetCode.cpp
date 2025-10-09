#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
for (int i = 0; i < nums.size(); i++) {  // stop at size()-2
     n^= nums[i];
}
return n;
    }
};