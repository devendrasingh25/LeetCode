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
    int removeStones(vector<vector<int>>& stones) {
        int maxi = 0 ;
        int total = 0 ;
        int n = stones.size();
        for(auto x : stones){
            maxi = max({maxi, x[0], x[1]});
        }
        if( maxi == 0 )return 0 ;
        int offset = maxi + 1;
        DisjointUnion dsu(2 * maxi + 2);
        for( int i =0 ;i < stones.size();i++){
            dsu.unionbyrank(stones[i][0],stones[i][1]+offset);
        }
        set<int> roots;
         for (int i = 0; i < n; i++) {
            roots.insert(dsu.find(stones[i][0]));
        }

      return n - (int)roots.size() ;
    }
};