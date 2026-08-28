class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int oddCnt = 0, oddChar = -1;
        for (int c = 0; c < 26; c++) {
            if (count[c] % 2 == 1) {
                oddCnt++;
                oddChar = c;
            }
        }

        if (n % 2 == 0) {
            if (oddCnt != 0) return "";
        } else {
            if (oddCnt != 1) return "";
        }
        char midChar = (n % 2 == 1) ? ('a' + oddChar) : 0;

        vector<int> freeCount(26, 0);
        for (int c = 0; c < 26; c++) freeCount[c] = count[c] / 2;

        int m = n / 2;
        string targetPrefix = target.substr(0, m);
        string targetSuffix = target.substr(m);

        vector<int> cur = freeCount;
        int best_i = -1;
        bool fullMatch = true;
        for (int i = 0; i < m; i++) {
            int t = targetPrefix[i] - 'a';
            bool found = false;
            for (int c = t + 1; c < 26; c++) {
                if (cur[c] > 0) { found = true; break; }
            }
            if (found) best_i = i;

            if (cur[t] > 0) {
                cur[t]--;
            } else {
                fullMatch = false;
                break;
            }
        }

        if (fullMatch) {
            string rest;
            if (n % 2 == 1) rest += midChar;
            string revPrefix = targetPrefix;
            reverse(revPrefix.begin(), revPrefix.end());
            rest += revPrefix;
            if (rest > targetSuffix) {
                return targetPrefix + rest;
            }
        }

        if (best_i == -1) return "";

        vector<int> cnt = freeCount;
        for (int i = 0; i < best_i; i++) {
            cnt[targetPrefix[i] - 'a']--;
        }

        int t = targetPrefix[best_i] - 'a';
        int chosen = -1;
        for (int c = t + 1; c < 26; c++) {
            if (cnt[c] > 0) { chosen = c; break; }
        }
        cnt[chosen]--;

        string h = targetPrefix.substr(0, best_i);
        h += ('a' + chosen);
        for (int c = 0; c < 26; c++) {
            h += string(cnt[c], 'a' + c);
        }

        string full = h;
        if (n % 2 == 1) full += midChar;
        string revH = h;
        reverse(revH.begin(), revH.end());
        full += revH;

        return full;
    }
};