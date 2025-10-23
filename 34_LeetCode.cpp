#include<bits/stdc++.h>
using namespace std;
class Solution {
    
public:

    int find(vector<int>& nums, int target,bool left){
        int s=0;
        int e=nums.size()-1;
        int ans =-1;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(target > nums[mid]){
                s= mid+1;
            }
            else if(target<nums[mid]){
                e=mid-1;
            }
            else{
                ans = mid;
                if(left){          
                    e=mid-1;
                }else{
                    s=mid+1;      
                }
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
      int left =  find(nums,target,true);
      int right = find(nums,target,false);
      return {left,right};
    }

    
};