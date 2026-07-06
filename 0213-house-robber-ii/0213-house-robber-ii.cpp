class Solution {
public:
    int check( int st ,int end ,vector<int>& nums){
        int prev = 0 ;
        int prev1 = 0 ;

        for( int i = st ; i <= end ; i++){
            int steal = nums[i] + prev ;
            int skip = prev1 ;
            int curr = max( steal ,skip );
             prev = prev1 ;
             prev1 = curr ;
        }
        return prev1 ;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int left = check( 0  , n-2 , nums );
        int right = check( 1, n-1 ,nums);

        return max(left , right) ;
        
    }
};