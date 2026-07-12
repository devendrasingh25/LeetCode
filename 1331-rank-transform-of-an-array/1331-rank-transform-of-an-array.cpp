class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr ;

        sort(ans.begin() , ans.end());
        unordered_map<int,int> rank  ;
        int r = 1 ;
        for(int num: ans ){
            if(rank.find(num) == rank.end()){
                rank[num] = r++;
            }
        }

        vector<int> ans1;
        ans1.reserve(arr.size());
        for (int num : arr) {
            ans1.push_back(rank[num]);
        }

        return ans1 ;
    }
};