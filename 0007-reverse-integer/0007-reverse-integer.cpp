class Solution {
public:
    int reverse(int n) {
         long long ans = 0;   

        while (n != 0) {
            int digit = n % 10;
            n /= 10;

            ans = (ans * 10) + digit;

            if (ans > INT_MAX || ans < INT_MIN) {
                return 0;
            }
        }

        return (int)ans;
    }
};