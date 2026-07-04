class Solution {
public:

   int check(int node , vector<vector<pair<int,int>>>&adj,vector<bool>&vis ){
        vis[node] = true ;
        int mini = INT_MAX ;
        for( auto x : adj[node]){
            int nb = x.first;
            int dis = x.second;
             mini = min(mini,dis);
            if( !vis[nb] ){
                vis[nb] = true;
                mini = min(mini,check(nb, adj , vis));
            }
        }
        return mini;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj (n+1);
        vector<bool> vis(n+1);
        
        for( auto it  : roads){
            int u = it[0];
            int v = it[1];
            int dis = it[2];

            adj[u].push_back({v,dis});
            adj[v].push_back({u,dis});
            
        }
        
      return check(1,adj,vis) ; 
    }
};