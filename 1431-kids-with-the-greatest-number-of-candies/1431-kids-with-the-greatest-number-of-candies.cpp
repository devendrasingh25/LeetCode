class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candy, int ext) {
        int n =INT_MIN;
        for(int i =0 ;i < candy.size() ; i++){
            n = max(n,candy[i]);
            
        }
        vector<bool> ans( candy.size()) ;
        for( int i=0 ; i < candy.size() ;i++ ){

            if( (candy[i]+ ext) >= n ){
                ans[i] = true ;
            }
            else{
                ans[i] = false;
            }

           
        }

         return ans;
    }
};