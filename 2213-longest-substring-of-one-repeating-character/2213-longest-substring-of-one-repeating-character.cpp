class Solution {
public:
    struct Node {
        int len;
        int prefLen, sufLen, maxLen;
        char leftChar, rightChar;
    };
    
    vector<Node> tree;
    string s;
    
    Node merge(Node& left, Node& right) {
        Node res;
        res.len = left.len + right.len;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;
        
        res.prefLen = left.prefLen;
        if (left.prefLen == left.len && left.rightChar == right.leftChar) {
            res.prefLen += right.prefLen;
        }
        
        res.sufLen = right.sufLen;
        if (right.sufLen == right.len && right.leftChar == left.rightChar) {
            res.sufLen += left.sufLen;
        }
        
        res.maxLen = max(left.maxLen, right.maxLen);
        if (left.rightChar == right.leftChar) {
            res.maxLen = max(res.maxLen, left.sufLen + right.prefLen);
        }
        
        return res;
    }
    
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }
    
    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, val, val};
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2*node, start, mid, idx, val);
        else update(2*node+1, mid+1, end, idx, val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }
    
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        int n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
        
        int k = queryCharacters.size();
        vector<int> result(k);
        
        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            this->s[idx] = c;
            update(1, 0, n - 1, idx, c);
            result[i] = tree[1].maxLen;
        }
        
        return result;
    }
};