class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        vector<vector<int>> ans ;
        sort(inter.begin() , inter.end());

        for( int i =0 ;i < inter.size() ;i++){
            int start = inter[i][0];
            int end = inter[i][1];
            if(!ans.empty() && end <= ans.back()[1] ) continue;

            for( int j =i+1 ; j < inter.size() ;j++){
              if ( inter[j][0] <= end){
                end = max( inter[j][1] , end);
              }
              else{
                break;
              }
            }

            ans.push_back({start, end}) ;
        }
        return ans;
    }
};