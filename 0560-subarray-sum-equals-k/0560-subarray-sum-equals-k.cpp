class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        map<int, int> m;
        int count=0, sum = 0;
        m[0] = 1;
        for (auto i : v) {
            sum += i;
            if (m.count(sum - k)) {
                count += m[sum - k];
            }
            m[sum]++;
        }
        return count;
    }
};