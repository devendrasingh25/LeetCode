class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adj(n);
        long long  mod = (int)(1e9+7);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
        vector<long long> dist (n,LLONG_MAX);
        vector<long long>path(n,0);
        for( int i =0 ;i < roads.size() ;i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        dist[0]=0;
        path[0]=1;
        q.push({0,0});

        while(!q.empty()){
            long long dis = q.top().first;
            int node= q.top().second;
            q.pop();

             if (dis > dist[node]) continue;

            for( auto x : adj[node]){
                long long d= x.second ;
                int nb = x.first;
     
                if( dis + d < dist[nb] ){
                    dist[nb] = dis+ d;
                    q.push({dis+d,nb});
                     path[nb] = path[node] % mod;
                }
                else if( dis+ d == dist[nb]){
                    path[nb] =( path[nb] + path[node]) % mod;
                }
            }
        }
        return path[n-1] % mod ;
    }
};