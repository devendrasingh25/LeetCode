class DisjointUnion {
public:
    vector<int> par, rank_;

    DisjointUnion(int n) {
        par.resize(n);
        rank_.assign(n, 0);
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unionbyrank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if (parA == parB) return;

        if (rank_[parA] == rank_[parB]) {
            par[parB] = parA;
            rank_[parA]++;
        }
        else if (rank_[parA] > rank_[parB]) {
            par[parB] = parA;
        }
        else {
            par[parA] = parB;
        }
    }
};

class Solution {
public:
   
    int minScore(int n, vector<vector<int>>& roads) {
       DisjointUnion dsu(n+1);

       for( auto it : roads){
         int u = it[0];
         int v = it[1];
          
          dsu.unionbyrank( u, v) ;
       }

       int t = dsu.find(1);
       int mini = INT_MAX;
        for( auto it : roads){
         int u = it[0];
         int v = it[1];
          int cost = it[2];
          
          if( dsu.find(u) == t){
            mini = min(mini,cost);
          }
       }
       return mini;
    }
};