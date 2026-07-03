class Solution {
public:
    typedef long long ll;
    bool check( int mid , int n , ll k , vector<vector<pair<int,int>>>&adj ){
        vector<ll> result (n, LLONG_MAX);

        priority_queue<pair< ll ,int> , vector<pair<ll,int>> , greater<pair<ll,int>>> q;
        result[0]=0;
        q.push({0,0});
        while(!q.empty()){
            ll dis = q.top().first;
            int node = q.top().second;
            q.pop();
            
             if( dis > k ) return false ;
             if( node == n-1) return true;
             if( result[node] < dis) continue ;

             for( auto x : adj[node]){
                int nb = x.first;
                int cost = x.second ;

                if( cost < mid) continue;

                if(( dis + cost < result[nb])){
                    result[nb] = dis+ cost ;
                    q.push({result[nb], nb});
                }
             }
        }
        return false ;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        
        int n  = online.size();
        vector<vector<pair<int,int>>> adj(n);
        int l = INT_MAX;
        int r = 0 ;
        for( auto it : edges){
           int u = it[0];
           int v = it[1];
           int cost = it[2];

           if( !online[u] || !online[v]){
            continue;
           } 
           adj[u].push_back({v,cost});
           l = min(l,cost);
           r = max( r, cost);
           
        }
        int ans = -1;
        while( l <= r ){
            int mid = l + (r-l)/2;
            if(check(mid,n,k, adj)){
                ans = mid ;
                l = mid+1;
            }
            else{
                r =mid - 1 ;
            }
        }
       
        return ans ;
    }
};