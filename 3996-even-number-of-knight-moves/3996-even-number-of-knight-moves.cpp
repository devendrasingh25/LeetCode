class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
       int colorSum = start[0] + start[1] + target[0] + target[1];
        return colorSum % 2 == 0;
        
    }
};