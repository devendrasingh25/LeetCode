class DisjointUnion {
public:
    vector<int> par, rank_, minEdge;

    DisjointUnion(int n) {
        par.resize(n);
        rank_.assign(n, 0);
        minEdge.assign(n, INT_MAX);
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unionbyrank(int a, int b, int w) {
        int parA = find(a);
        int parB = find(b);

        if (parA == parB) {
            minEdge[parA] = min(minEdge[parA], w);
            return;
        }

        if (rank_[parA] == rank_[parB]) {
            par[parB] = parA;
            minEdge[parA] = min({minEdge[parA], minEdge[parB], w});
            rank_[parA]++;
        }
        else if (rank_[parA] > rank_[parB]) {
            par[parB] = parA;
            minEdge[parA] = min({minEdge[parA], minEdge[parB], w});
        }
        else {
            par[parA] = parB;
            minEdge[parB] = min({minEdge[parA], minEdge[parB], w});
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointUnion dsu(n + 1);

        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            dsu.unionbyrank(u, v, w);
        }

        return dsu.minEdge[dsu.find(1)];
    }
};