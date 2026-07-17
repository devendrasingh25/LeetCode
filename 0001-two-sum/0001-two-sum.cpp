class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
       vector<pair<int,int>>arr ;
       for( int i = 0 ; i< nums.size() ; i++){
          arr.push_back({nums[i] , i}) ;

       } 
       vector<int> ans ;
       sort( arr.begin(),arr.end());
       int i =0 , j = nums.size()-1 ;

       while( i<j){
        int sum = arr[i].first + arr[j].first ;

        if( sum > target){
            j--;
        }
        else if( sum < target){
             i++;
        }
        else{
            ans.push_back(arr[i].second);
            ans.push_back(arr[j].second);
            break;
        }
       }
       return ans;
    }
};