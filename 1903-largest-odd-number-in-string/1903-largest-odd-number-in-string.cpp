class Solution {
public:
    string largestOddNumber(string num) {
       int in = -1 ;
       for(int i =num.size()-1  ; i >= 0 ;i--){
           
           if( (num[i] - '0')%2 == 1){
              in = i ;
              break ;
           }
       }
       if(in == -1) return "";
       string ans ="";
       for(int i =0 ; i <= in ;i++){
          ans+=num[i];
       }
       return ans;
    }
};