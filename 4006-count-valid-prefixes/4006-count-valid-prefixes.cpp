class Solution {
public:
    int countValidPrefixes(string s) {
        int res = 0 , diff =0 ;

        for(auto ch : s) {
            diff += ch == '1' ? 1 :-1 ;
            res += abs(diff) <= 1;

        }
        return res;
    }
};