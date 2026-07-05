class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0 ,high = nums.size() -1 ;

        while( l< high) {

            int mid = l + ( high - l )/2;

            if(nums[mid] > nums[high]){
                l = mid+1;
            }
            else if (nums[mid] < nums[high]){
                high = mid ;
            }
            else{
                high -- ;
            }
        }

        return nums[l];
    }
};