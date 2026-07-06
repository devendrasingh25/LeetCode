class Solution {
public:
    
    int rob(vector<int>& nums) {
         int n  = nums.size();
         if( n == 1) return nums[0] ;
        
          int prev = 0 ;
          int prev1 = nums[0];
         for( int i = 2 ; i<= n  ; i++){
             int steal = nums[i-1] + prev;
             int skip = prev1;
             
           int curr = max(steal,skip);
            prev = prev1 ;
            prev1 = curr ;
        
         }
         return prev1 ;
    }
};