#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
         string result = "";
    int depth = 0;

    for (char c : s) {
        if (c == '(') {
            if (depth > 0) result += c; // not the outermost '('
            depth++;
        } else if (c == ')') {
            depth--;
            if (depth > 0) result += c; // not the outermost ')'
        }
    }
    return result;

    }
};