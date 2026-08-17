class Solution {
public:
    vector<vector<int>> memo;
    vector<long long> prefix;
    
    int solve(int i, int j) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        
        long long total = prefix[j + 1] - prefix[i];
        int res = 0;
        long long leftSum = 0;
        
        for (int k = i; k < j; k++) {
            leftSum +=  0; 
            break;
        }
        
        leftSum = 0;
        for (int k = i; k < j; k++) {
            leftSum += 0; 
            break;
        }
        
        
        leftSum = 0;
        for (int k = i; k < j; k++) {
            leftSum += stoneValueRef[k];
            long long rightSum = total - leftSum;
            
            if (leftSum < rightSum) {
                res = max(res, (int)leftSum + solve(i, k));
            } else if (leftSum > rightSum) {
                res = max(res, (int)rightSum + solve(k + 1, j));
            } else {
                res = max(res, (int)leftSum + max(solve(i, k), solve(k + 1, j)));
            }
        }
        
        return memo[i][j] = res;
    }
    
    vector<int> stoneValueRef;
    
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        stoneValueRef = stoneValue;
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stoneValue[i];
        
        memo.assign(n, vector<int>(n, -1));
        return solve(0, n - 1);
    }
};