class Solution {
public:
    long long sumAndMultiply(int n) {
        string ans = "" ;
        
        string into = to_string(n);
        long long  sum = 0; 
        for( int i =0 ;i < into.length() ;i++){
            if( into[i] != '0'){
                ans += into[i];
                sum += (into[i] -'0');
            }
        } 
       if (ans.empty()) ans = "0";
        long long  final = stoll(ans);
       long long result = final*sum ;

       return result ;
    }
        
};