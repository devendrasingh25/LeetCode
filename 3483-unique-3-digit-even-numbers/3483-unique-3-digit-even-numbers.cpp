class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> results;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int l = 0; l < n; l++) {
                    if (l == i || l == j) continue;

                    if (digits[i] == 0) continue;       
                    if (digits[l] % 2 != 0) continue;   

                    int num = digits[i] * 100 + digits[j] * 10 + digits[l];
                    results.insert(num);
                }
            }
        }

        return results.size();
    }
};