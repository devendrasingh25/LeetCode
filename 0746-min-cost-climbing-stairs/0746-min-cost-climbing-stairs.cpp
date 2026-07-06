class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prv = 0;
        int prv1 = 0 ;

        for (int i = 2; i <= n; i++) {
            int left = prv + cost[i - 1];
            int right = prv1 + cost[i - 2];
            int curr = min(left, right);
             prv1 = prv ;
             prv  = curr ;
        }

        return prv;
    }
};