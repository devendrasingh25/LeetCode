class Solution {
public:
    const long long CAP = 1000001;  

    long long nCr(int n, int r, long long cap) {
        if (r > n - r) r = n - r;
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > cap) return cap;
        }
        return res;
    }

    long long permCount(vector<int>& counts, int length) {
        long long result = 1;
        int remaining = length;
        for (int c = 0; c < 26; c++) {
            if (counts[c] == 0) continue;
            result = result * nCr(remaining, counts[c], CAP);
            if (result >= CAP) return CAP;
            remaining -= counts[c];
        }
        return result;
    }

    string smallestPalindrome(string s, long long k) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        char middle = '\0';
        vector<int> halfCounts(26, 0);
        int halfLen = 0;

        for (int c = 0; c < 26; c++) {
            if (freq[c] % 2 != 0) middle = 'a' + c;
            halfCounts[c] = freq[c] / 2;
            halfLen += halfCounts[c];
        }

        long long total = permCount(halfCounts, halfLen);
        if (total < k) return "";

        string half = "";
        long long remainingK = k;
        int remainingLen = halfLen;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (halfCounts[c] == 0) continue;

                halfCounts[c]--;
                long long cnt = permCount(halfCounts, remainingLen - 1);

                if (remainingK <= cnt) {
                    half += ('a' + c);
                    remainingLen--;
                    break;
                } else {
                    remainingK -= cnt;
                    halfCounts[c]++;
                }
            }
        }

        string rightHalf = half;
        reverse(rightHalf.begin(), rightHalf.end());

        string result = half;
        if (middle != '\0') result += middle;
        result += rightHalf;

        return result;
    }
};