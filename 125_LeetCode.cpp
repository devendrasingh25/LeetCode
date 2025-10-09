
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;  // two pointers

        while (left < right) {
            // skip non-alphanumeric from left
            while (left < right && !isalnum(s[left])) left++;

            // skip non-alphanumeric from right
            while (left < right && !isalnum(s[right])) right--;

            // compare characters (ignore case)
            if (tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;
        }

        return true; // all matched, it's a palindrome
    }
};
