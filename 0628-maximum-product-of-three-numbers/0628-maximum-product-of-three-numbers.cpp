class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi =INT_MIN , maxi1 = INT_MIN , maxi2 = INT_MIN , min1= INT_MAX , min2 = INT_MAX;
        
        for( int i =0 ;i < nums.size() ;i++){
            if( nums[i] > maxi){
                maxi2 = maxi1;
                maxi1 = maxi; 
                maxi = nums[i];

            }
            else if( nums[i] > maxi1){
                maxi2= maxi1 ;
                maxi1 = nums[i];
            }
            else if( nums[i] > maxi2){
                maxi2 = nums[i];
            }
             if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            }
            else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
          return max(maxi1*maxi2*maxi ,maxi*min1*min2);
    }
};