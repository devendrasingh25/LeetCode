class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int left = 0;
        int result = 0;
        
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            
            while (freq[s[right]] > 2) {
                freq[s[left]]--;
                left++;
            }
            
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};