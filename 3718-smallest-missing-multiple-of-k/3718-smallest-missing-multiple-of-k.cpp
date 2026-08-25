class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> ans;
        for( int i =0 ;i < nums.size() ;i++){
            if(nums[i] % k == 0){
                ans.push_back(nums[i]);
            }
        }
        sort(ans.begin() , ans.end());
        int count = 1 ;
       
        for( int i = 0 ; i < ans.size() ;i++ ){
               if(k*count == ans[i]){
                 count++;
               }
               
        }
        return k*count;
    }
};