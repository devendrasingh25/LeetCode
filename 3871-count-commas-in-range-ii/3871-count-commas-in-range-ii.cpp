class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long lo = 1, hi = 9;
        long long digits = 1;

        while (lo <= n) {
            long long upper = min(n, hi);
            long long cnt = upper - lo + 1;
            long long commasPerNumber = (digits - 1) / 3;
            total += cnt * commasPerNumber;

            lo = hi + 1;
            hi = hi * 10 + 9;
            digits++;
        }

        return total;
    }
};