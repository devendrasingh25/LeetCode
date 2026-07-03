class Solution {
public:
    bool rotateString(string s, string goal) {
          if (s.size() != goal.size()) return false; 
          if (s.empty() && goal.empty()) return true;
        for( int i =0 ;i < s.size() ; i++){
            if( goal !=  s){
                char n = s[0];
                s.erase(s.begin());
                s += n ;
            }
            else{
                return true;
            }
        }
        return false;
    }
};