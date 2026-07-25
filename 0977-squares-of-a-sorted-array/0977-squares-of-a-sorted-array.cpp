class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1, pos = n - 1;
        vector<int> ans(n);
        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])){
                ans[pos] = nums[i] * nums[i];
                i++;
            }  
            else {
                ans[pos] = nums[j] * nums[j];
                j--;
            }
            pos--;
        }
        return ans;
    }
};