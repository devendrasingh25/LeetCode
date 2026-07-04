class Solution {
public:
    int compress(vector<char>& chars) {
        int n  =chars.size();
        int index = 0;
        int i =0 ;
         while(i<n){
            int curr_char = chars[i];
            int count =0 ;
            while(i < n && curr_char == chars[i]){
                count++;
                i++;
            }
           
               chars[index] = curr_char;
               index++;
               
               if( count > 1){
                  string ans = to_string(count);

                   for( auto x : ans){
                     chars[index] = x ;
                    index++ ;
                   }
               }

              
            

         }
         return index ;
    }
};