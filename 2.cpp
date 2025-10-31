#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::string frequencySort(const std::string &s) {
    std::unordered_map<char, int> freq;

    // Step 1: Count frequency of each character
    for (char ch : s) {
        freq[ch]++;
    }

    // Step 2: Move to vector for sorting
    std::vector<std::pair<char, int>> freqVec(freq.begin(), freq.end());

    // Step 3: Sort by descending frequency
    std::sort(freqVec.begin(), freqVec.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });

    // Step 4: Build result string
    std::string result;
    for (const auto &[ch, count] : freqVec) {
        result.append(count, ch); // repeat character 'count' times
    }

    return result;
}