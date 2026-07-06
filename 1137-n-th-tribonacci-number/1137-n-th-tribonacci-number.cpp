class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

      
       int prv = 1;
       int prv1 = 1 ;
        int prv2 = 0 ;
        

        for( int i = 3 ; i <= n ;i++){
           int ans  = prv + prv1 + prv2 ;
           prv2 = prv1;
            prv1 = prv;
            prv = ans;
          
        }

        return prv ;
    }
};