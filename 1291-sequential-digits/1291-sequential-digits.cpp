class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans ;
        for( int i =2 ; i < 10  ; i++){
            for( int j =0 ; j <= s.length() - i ; j++){
                int digit = stoi(s.substr(j,i));
                if(digit >= low &&  digit <= high){
                    ans.push_back(digit);
                }
            }
        }
        return ans;
    }
};