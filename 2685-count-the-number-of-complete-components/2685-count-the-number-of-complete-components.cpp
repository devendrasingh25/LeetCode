class Solution {
public:
    vector<int> parent, rankArr;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return;
        if (rankArr[ra] < rankArr[rb]) swap(ra, rb);
        parent[rb] = ra;
        if (rankArr[ra] == rankArr[rb]) rankArr[ra]++;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rankArr.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);

        for (auto& e : edges) {
            unite(e[0], e[1]);
        }

        vector<long long> vertexCount(n, 0), edgeCount(n, 0);

        for (int i = 0; i < n; i++) {
            vertexCount[find(i)]++;
        }
        for (auto& e : edges) {
            edgeCount[find(e[0])]++;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                long long v = vertexCount[i];
                long long need = v * (v - 1) / 2;
                if (edgeCount[i] == need) result++;
            }
        }
        return result;
    }
};