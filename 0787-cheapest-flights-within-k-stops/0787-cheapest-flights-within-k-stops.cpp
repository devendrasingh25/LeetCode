class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int,int>>> adj(n);
       vector<int>dist(n,INT_MAX);
       queue <pair<pair<int,int>,int>> q;
       for( int i =0 ; i < flights.size() ; i++){
          adj[flights[i][0]].push_back({flights[i][1] , flights[i][2]});
       }
        dist[src] = 0;
       q.push({{src,0},-1});
       while(!q.empty()){
        int node = q.front().first.first;
        int cost = q.front().first.second;
        int stop = q.front().second;
        q.pop();

        for( auto x : adj[node]){
           int v = x.first;
           int wt = x.second;  

           if( dist[v] > cost + wt && stop+1 <= k ){
            dist[v] = cost + wt ;
            q.push({{v, wt+ cost}, stop +1});
           }
        }
       }

       if(dist[dst] == INT_MAX) return -1;

       return dist[dst] ;
    }
};