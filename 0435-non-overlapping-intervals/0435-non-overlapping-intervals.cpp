class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        int count = 0 ;
        int n = inter.size();
         
        if (n == 0) return 0;

        sort(inter.begin(), inter.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int last = inter[0][1];
         for( int i =1 ; i < n  ;i++){
           if( inter[i][0] < last){
            count++;
           }
           else{
             last = inter[i][1];
           }
            
         }
         return count;
    }
};