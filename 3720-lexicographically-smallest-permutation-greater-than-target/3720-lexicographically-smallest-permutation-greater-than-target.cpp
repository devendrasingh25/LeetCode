class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cur(26, 0);
        for (char c : s) cur[c - 'a']++;

        int best_i = -1;

        for (int i = 0; i < n; i++) {
            int t = target[i] - 'a';
            bool found = false;
            for (int c = t + 1; c < 26; c++) {
                if (cur[c] > 0) {
                    found = true;
                    break;
                }
            }
            if (found) best_i = i;

            if (cur[t] > 0) {
                cur[t]--;
            } else {
                break;
            }
        }

        if (best_i == -1) return "";

        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        for (int i = 0; i < best_i; i++) {
            cnt[target[i] - 'a']--;
        }

        int t = target[best_i] - 'a';
        int chosen = -1;
        for (int c = t + 1; c < 26; c++) {
            if (cnt[c] > 0) {
                chosen = c;
                break;
            }
        }

        cnt[chosen]--;

        string result = target.substr(0, best_i);
        result += ('a' + chosen);

        for (int c = 0; c < 26; c++) {
            result += string(cnt[c], 'a' + c);
        }

        return result;
    }
};