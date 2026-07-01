class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
      if(grid[0][0] == 1 || grid[n-1][n-1]) return 0 ;  
      vector<vector<int>> safe(n,vector<int>(n,-1));
      queue<pair<int,int>> q;

      for( int i =0 ;i < n ;i++){
        for( int j =0 ;j<n ;j++){
            if( grid[i][j] == 1){
                safe[i][j] = 0;
                q.push({i,j});
            }
        }
      } 
       int dr[] ={-1,0,+1,0};
       int dc[] = {0,+1,0,-1};

      while(!q.empty()){
        int r= q.front().first;
        int c =q.front().second;
        q.pop();
         
         for( int in =0 ; in< 4 ;in++){
             int nr = r + dr[in];
             int nc  = c +dc[in];
             if(nr>=0 && nc>=0 && nr <n && nc <n && safe[nr][nc] == -1){
                   safe[nr][nc] = safe[r][c] +1 ;
                   q.push({nr,nc});
             }
         }
        
      }
      vector<vector<int>> best ( n, vector<int>(n,-1));
      priority_queue<pair<int,int>>pq;
      pq.push({safe[0][0],0});
      best[0][0]=safe[0][0];
      while(!pq.empty()){
            auto [s, code] = pq.top();
            pq.pop();
            int x = code / n, y = code % n;

            if( s < best[x][y] ) continue;

            for( int i =0 ; i < 4 ;i ++){
                int nr = x+ dr[i];
                int nc = y + dc[i];
                if( nr>=0 && nc>=0&& nr < n && nc< n){
                    int candidate = min(s, safe[nr][nc]);
                    if(candidate> best[nr][nc]){
                        best[nr][nc] = candidate ;
                        pq.push({candidate,nr*n+nc});
                    }
                }
            }
 
      }
      return best[n-1][n-1];
    }
};