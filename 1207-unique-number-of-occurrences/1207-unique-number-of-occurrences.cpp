class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) freq[num]++;

        vector<int> counts;
        for (auto& [val, count] : freq) counts.push_back(count);

        sort(counts.begin(), counts.end());

        for (int i = 1; i < counts.size(); i++) {
            if (counts[i] == counts[i-1]) return false;
        }

        return true;
    }
};