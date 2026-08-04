class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for( int i = 0 ; i< nums.size()-1 ; i++){
           if( nums[i+1] != nums[i]+1){
            int last = nums[i]+1;
            int max = nums[i+1];
             while (last != max){
                ans.push_back(last);
                last++;
                
             }
           }
        }
        return ans;
    }
};