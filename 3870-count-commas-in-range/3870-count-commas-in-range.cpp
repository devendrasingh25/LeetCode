class Solution {
public:
    int calc(int n) {
        int count = 0;
        while (n > 0) {
            n = n / 10;
            count++;
        }
        return count;
    }

    int countCommas(int n) {
        int total = 0;
        for (int x = 1; x <= n; x++) {
            int m = calc(x);
            total += (m - 1) / 3;
        }
        return total;
    }
};