class Solution {
public:
    
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
            for (int i = 0; i < n; i++) dist[i][i] = 0;
        for(int i =0 ; i< edges.size();i++){
            dist[edges[i][0]][edges[i][1]] = edges[i][2] ;
            dist[edges[i][1]][edges[i][0]] = edges[i][2] ;
        }
        

        for( int k =0 ; k < n ; k ++){
            for(int i =0 ;i <n ;i++){
                for(int j =0 ;j<n ;j++){

                   if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX){ 
                    dist[i][j] = min(dist[i][j] ,dist[i][k]+dist[k][j]);}
                }
            }
        }
          int ans = -1, fewest = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (i != j && dist[i][j] <= k) cnt++;

            if (cnt <= fewest) {
                fewest = cnt;
                ans = i;
            }
        }
        return ans;

    }
};