class Solution {
public:
    bool isPalindromic(string s) {
        string bin = "";
        for (char c : s) {
            for (int bit = 7; bit >= 0; bit--) {
                bin.push_back(((c >> bit) & 1) ? '1' : '0');
            }
        }
        int i = 0, j = bin.length() - 1;
        while (i < j) {
            if (bin[i] != bin[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};