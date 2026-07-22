class Solution {
public:
void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());

    int mid = (n - 1) / 2;     
    int right = n - 1;          

    for (int i = 0; i < n; i++) {
        nums[i] = (i % 2 == 0) ? sorted_nums[mid--] : sorted_nums[right--];
    }
}
};