class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
      vector<bool> ans;
      vector<int>path(n);
      int c = 0 ;
      for( int i =1  ; i < n ; i++){
       if  (nums[i] - nums[i-1] > maxDiff ) c++ ;
        path[i] = c ;
      }

      for( auto p : queries){
          ans.push_back(path[p[0]] == path[p[1]]);
      }
      return ans ;
    }
};