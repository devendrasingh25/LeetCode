class Solution {
public:
    string smallestSubsequence(string s) {
       int n = s.size() ;
       vector<int> lastindex(26);
       vector<bool> taken( 26 ,false);  

       string result ="";

       for( int i = 0 ;i < n ;i++){
         int idx = s[i] - 'a' ;

         lastindex[idx] = i ;
       }

       for( int i =0 ;i < n ;i++){
          int idx = s[i] - 'a' ;

          if( taken[idx] == true) continue ;

          while( result.length() > 0 &&  result.back() > s[i] && lastindex[result.back() - 'a'] > i ){
            taken[result.back() - 'a'] = false ;
            result.pop_back();
          }

          result.push_back(s[i]);
          taken[idx] = true ;
        
       }

       return result ;
    }
};