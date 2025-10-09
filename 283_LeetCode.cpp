#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int j = 0; // position to place next non-zero

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (i != j) {
                    swap(nums[i], nums[j]);  // swap only when i and j differ
                }
                j++;
            }
        }
         }
    
};