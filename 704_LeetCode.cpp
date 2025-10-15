#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 int search(vector<int>& nums, int target) {
    int st = 0; 
    int end = nums.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (nums[mid] == target) {
            return mid;
        } 
        else if (nums[mid] < target) {
            st = mid + 1;  // search in right half
        } 
        else {
            end = mid - 1; // search in left half
        }
    }

    return -1; // not found
}
};