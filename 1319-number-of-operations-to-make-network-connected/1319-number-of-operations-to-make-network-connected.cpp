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
  
    int makeConnected(int n, vector<vector<int>>& connections) {
        int comp = 0;
        int edges = 0;
        DisjointUnion dsu(n);
        for( int i =0 ;i < connections.size() ; i++){
            if(  dsu.find(connections[i][0]) == dsu.find(connections[i][1])){
                edges++;
            }
            else{
            dsu.unionbyrank(connections[i][0],connections[i][1]);
            }
        }

        for( int i =0 ;i < n ;i++){
            if( dsu.par[i] == i){
              comp++;
            }
        }
        int ans = comp -1 ;
        if( edges >= ans ){
            return ans ;
        }
       return -1;
    }
};