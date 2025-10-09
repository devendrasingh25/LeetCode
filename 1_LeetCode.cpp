#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
 unordered_map<int, int> m;  // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];   // calculate the required number
            if (m.count(rem)) {
                return {m[rem], i};  // found the pair
            }
            m[nums[i]] = i;  // store the current number with its index
        }

        return {};  // not expected to be reached (problem guarantees a solution)

      }   
    
};