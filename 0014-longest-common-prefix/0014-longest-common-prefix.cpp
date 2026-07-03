class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         
         string prefix = strs[0];
         if( prefix.length() == 0) return "";
         for( int i = 1 ; i< strs.size() ;i++){
            int j =0 ; 
             int z = min( prefix.length() , strs[i].length());
             while( j < z && prefix[j] == strs[i][j]){
                j++;
             }

              prefix = prefix.substr(0, j);  
            if (prefix.empty()) return "" ; 
         }
          
           

       return prefix ;
    }
};