class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
         int m  = inter.size();
        
       sort(inter.begin(), inter.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int iv = 0 ;
        int count = 0 ;

        for( int i =0 ;i < m ;i++){
            if( inter[i][1] <= iv )continue;

            iv = inter[i][1];
            count++ ;
        }

        return count ;
    }
};