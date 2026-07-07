class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>q;
        for( int i=0 ;i < nums.size() ;i++){
            q.push(nums[i]);
        }
        int count  = 0;
        int ans = 0;
        while(!q.empty()){
            int n = q.top();
            q.pop();
            if(count ==  k-1){
                ans =  n ;
                break;
            }
            count ++;
        }

        return ans ;
    }
};