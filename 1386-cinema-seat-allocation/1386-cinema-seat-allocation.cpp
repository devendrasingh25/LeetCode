class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        unordered_map<int, set<int>> reserved;
        for (auto& s : res) {
            reserved[s[0]].insert(s[1]);
        }

        int count = 2 * (n - (int)reserved.size());  

        for (auto& [row, seats] : reserved) {         
            bool left = true, mid = true, right = true;

            for (int j = 2; j <= 5; j++)
                if (seats.count(j)) left = false;

            for (int j = 4; j <= 7; j++)
                if (seats.count(j)) mid = false;

            for (int j = 6; j <= 9; j++)
                if (seats.count(j)) right = false;

            if (left && right) count += 2;
            else if (left || mid || right) count += 1;
        }

        return count;
    }
};