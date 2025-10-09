#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0 ; 
        int value =0 ;
        for ( int i = 0 ; i < nums.size() ; i ++ ){

            if ( nums[i] == 1 ){
                count ++ ;
               value = max(value,count);

            }
            else{
                count = 0 ;
            }
        }
        return value ;
    }
};