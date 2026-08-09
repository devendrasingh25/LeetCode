 // code for merge sort

 #include <bits/stdc++.h>
using namespace std;    

int main(){
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    int sum = 0;

    for(int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }

    cout << sum << endl;
    return 0;
}