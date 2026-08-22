class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 ;
        int prod = 1 ;
        int no = n ;

        while( n != 0 ){
            int digit  =  n % 10 ;
             n /= 10 ;

             sum += digit ;
             prod *= digit ;
        }

        int f = sum + prod ;

        return ( no % f) == 0 ? true : false;
    }
};