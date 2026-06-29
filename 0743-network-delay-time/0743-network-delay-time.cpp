class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj (n+1);
        int ans = 0 ;
        vector<int> vis (n+1,INT_MAX);
        for( int i =0 ;i < times.size() ;i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        } 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0 , k});
        vis[k] = 0 ;
        while(!q.empty()){
            int node = q.top().second;
            int time = q.top().first;
            q.pop();

            for( auto x : adj[node]){
                int nb = x.first;
                int t = x.second ;

                if( time + t < vis[nb]){
                    vis[nb] = time+t;
                    q.push({time+t , nb});
                } 
            }
        } 
       
        for( int i = 1 ; i< vis.size() ; i++){
            if (vis[i] == INT_MAX) return -1;
           ans = max(vis[i] ,ans);
        }
        return ans;
    }
};