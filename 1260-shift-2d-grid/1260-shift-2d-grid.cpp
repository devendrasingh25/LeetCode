class Solution {
public:
    void shift(vector<int>&na , int k ){
        int n = na.size();
        k %= n;
        reverse(na.begin(), na.end());
        reverse(na.begin() , na.begin()+k);
        reverse(na.begin()+k , na.end());

       
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> na;
       
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for( int i =0 ;i < n ;i++){
            for( int  j = 0 ; j < m  ; j ++){
                na.push_back(grid[i][j]);
            }
        } 
         k %= (n * m);
         shift(na,k);

        int l = 0 ;
       for( int i =0 ; i < n ;i++){
        for( int j =0 ; j < m ;j++){
            ans[i][j] = na[l];
            l++;
        }
         
       }
       return ans;
    }
};