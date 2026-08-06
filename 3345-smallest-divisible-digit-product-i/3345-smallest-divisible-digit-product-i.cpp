class Solution {
public:
    long long smallestNumber(long long n, int t) {
        long long candidate = n;

        while (true) {
            long long product = 1;
            long long temp = candidate;

            while (temp > 0) {
                product *= (temp % 10);
                temp /= 10;
            }

            if (product % t == 0) {
                return candidate;
            }

            candidate++;
        }
    }
};