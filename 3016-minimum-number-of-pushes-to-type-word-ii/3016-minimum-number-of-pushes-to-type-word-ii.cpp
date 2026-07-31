class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
         
    vector <int> hash (26 , 0) ;

        for( int i =0 ;i < n  ;i++){
            int u = (word[i] - 'a');
            hash[u]++;
        }
         sort( hash.begin() ,hash.end());
         reverse( hash.begin() ,hash.end());
         
           int ans = 0;
           for (int i = 0; i < 26; i++) {
            if (hash[i] == 0) break;

            int cost = (i / 8) + 1;
            ans += cost * hash[i];
           }
         
         return ans;
    }
};