class Solution {
public:
    long long gcdSum(vector<int>& nums) {
       
        vector<int> gcd ;
        int n = INT_MIN ;
        for( int  i=0 ; i < nums.size() ;i++){
             n = max( n , nums[i]);
            gcd.push_back(__gcd(nums[i],n));
        }

        sort(gcd.begin(),gcd.end());

        int i = 0, j = nums.size()-1   ;
        long long sum = 0 ;
        while( i < j ){
           sum += __gcd(gcd[i],gcd[j]);
           i++;
           j--;
        }

        return sum ;
    }
};