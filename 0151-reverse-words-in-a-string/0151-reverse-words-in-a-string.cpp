class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string ans ="";
        for( int i = 0 ; i< s.size(); i++){
            
            if(s[i] != ' ' ){
                ans+=s[i];
            }
            else if( s[i] == ' '){
              if(!ans.empty()){
                st.push(ans);
                ans ="";
              }
            }
        }
        if(!ans.empty()){
            st.push(ans);
        }
        string result ="";
        while(!st.empty()){
            result += st.top();
            st.pop();
            if(!st.empty()) result+=" ";
        }
        return result;
    }
};