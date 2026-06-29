class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int> >adj(n , vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;  
        pq.push({0,{0,0}});
        adj[0][0]=0;
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};

        while(!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second .second;
            pq.pop();
           if (r == n-1 && c == m-1) return diff;  
            
            for( int i =0 ; i < 4 ;i++){
                int nr = r +dr[i];
                int nc = c +dc[i];
                if( nr >= 0 && nr <n && nc>= 0 && nc<m ){
                     int nf = max(diff, abs(heights[r][c] - heights[nr][nc])) ;
                     if( nf < adj[nr][nc]){
                        adj[nr][nc] = nf ;
                        pq.push({adj[nr][nc],{nr,nc}});
                     }   
                    
                }
            }
        }
        return adj[n-1][m-1];
    }
};