class Solution {
public:
    
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX/2));
           
       for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (auto& it : edges) {
            int u=it[0],v=it[1],wt=it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;   // undirected: seed both directions
        }

        

        for( int k =0 ; k < n ; k ++){
            for(int i =0 ;i <n ;i++){
                for(int j =0 ;j<n ;j++){

                   if (dist[i][k] + dist[k][j] < dist[i][j]){ 
                    dist[i][j] = dist[i][k]+dist[k][j];
                    }
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