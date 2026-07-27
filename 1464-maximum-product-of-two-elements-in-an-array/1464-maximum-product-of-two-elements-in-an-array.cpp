class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int maxi = INT_MIN ,maxi1 = INT_MIN;

       for( int i =0 ;i < nums.size() ;i++){
         if( maxi < nums[i]){
            maxi1 = maxi ;
            maxi = nums[i];
         }
         else if( maxi1  < nums[i]){
            maxi1 = nums[i];
         }
       }

       return (( maxi-1) * ( maxi1 - 1));
    }
};