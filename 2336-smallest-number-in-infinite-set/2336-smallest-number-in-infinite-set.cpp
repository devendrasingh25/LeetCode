class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    unordered_set<int> inHeap; 

    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            q.push(i);
            inHeap.insert(i);
        }
    }

    int popSmallest() {
        int n = q.top();
        q.pop();
        inHeap.erase(n);
        return n;
    }

    void addBack(int num) {
        if (inHeap.find(num) == inHeap.end()) {
            q.push(num);
            inHeap.insert(num);
        }
    }
};