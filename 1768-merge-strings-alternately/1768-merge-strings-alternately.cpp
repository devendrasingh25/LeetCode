class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        int l = 0;
        int r = 0;
        int n1 = word1.size();
        int n2 = word2.size();

        while (l < n1 || r <n2) {
            if (l < n1) { 
                ans += word1[l];
                l++;
            }
            if (r < n2) {
                ans += word2[r];
                r++;
            }
        }

        return ans;
    }
};