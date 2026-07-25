class Solution {
public:
    int maxProduct(int n) {
       
        int  maxi1 = INT_MIN;
        int maxi = INT_MIN ;
        while( n !=  0 ){
            int digit = n % 10 ;
             if(maxi <= digit ){
                maxi1 = maxi;
                maxi = digit;
                
             }
             else if ( maxi1 <= digit ){
                maxi1 = digit ;
             }
             

             n /= 10 ;
        }
        return maxi * maxi1;
    }
};