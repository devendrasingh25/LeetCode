class Solution {
public:
    string largestOddNumber(string num) {
       int in = -1 ;
       for(int i =num.size()-1  ; i >= 0 ;i--){
           string g = "";
           g += num[i];
           int n = stoi(g);
           if( n % 2 !=0){
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