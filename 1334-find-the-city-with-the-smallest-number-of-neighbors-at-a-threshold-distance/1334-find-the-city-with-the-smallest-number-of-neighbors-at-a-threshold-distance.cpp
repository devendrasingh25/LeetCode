class Solution {
public:
    vector<int>check( int n, vector<vector<pair<int,int>>>adj , int src){
        vector<int> dist (n+1,INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> q;
        dist[src]=0;
        q.push({0,src});
        while(!q.empty()){
            int node = q.top().second;
            int dis  = q.top().first;
            q.pop();
             if(dis > dist[node])
                    continue;

            for(auto x :adj[node]){
                int nb =x.first;
                int d =x.second;
                if( dist[node] + d < dist[nb]){
                    dist[nb] = dist[node]+d;
                    q.push({dist[node]+d,nb});
                }
            }
        }
        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<int> reach(n+1,0);
        vector<vector<pair<int,int>>>adj(n+1);
        for( int i =0 ; i< edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
       int bestCity = -1, minReach = INT_MAX;

        for(int city = 0; city < n; city++){
            vector<int> dist = check(n, adj, city);
            int reach = 0;
            for(int j = 0; j < n; j++)
                if(j != city && dist[j] <= k) reach++;

           
            if(reach <= minReach){
                minReach = reach;
                bestCity = city;
            }
        }
        return bestCity;
    }
};