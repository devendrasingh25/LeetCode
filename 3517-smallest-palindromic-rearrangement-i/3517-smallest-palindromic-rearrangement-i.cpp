class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        map<char,int> freq ;
        for(auto it : s){
            freq[it]++;
        }

       char odd = '\0';

       string left ="";
       for( auto [ it, count] : freq){
          if( count % 2 != 0 ){
             odd = it;
          }

          left += string(count / 2, it) ;
       }
       string right = "";
       right = left ;
       reverse(right.begin() , right.end());

        string middle = (odd != '\0') ? string(1, odd) : "";

        return left + middle + right ;
    }
};