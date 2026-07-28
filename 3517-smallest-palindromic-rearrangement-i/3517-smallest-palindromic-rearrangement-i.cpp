class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string ans ="";
        for( int i = 0 ;i < n/2 ;i++){
            ans.push_back(s[i]);
        }
        sort(ans.begin(),ans.end());
        string res = ans;
         reverse(res.begin() , res.end());
        if( n%2 == 0){
            ans += res;
        }
        else{

            ans =  ans + s[n/2] + res;
        }

       return ans;
    }
};