class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m  =grid.size();
        int n = grid[0].size();

        vector<vector<int>> adj(m,vector<int>(n,0));
         
         for( int i=0 ;i<m ;i++){
            for( int j =0 ; j<n ;j++){
                if( i ==0 && j ==0 ) {
                adj[i][j] = grid[i][j];
                 continue;
                }
                else{
                    int up = INT_MAX ;
                    int left = INT_MAX;
                    if(i>0) up = grid[i][j] + adj[i-1][j];
                    if(j>0) left = grid[i][j] + adj[i][j-1]; 

                    adj[i][j] = min (up ,left);
                }
            }
         }
         return adj[m-1][n-1];
    }
};