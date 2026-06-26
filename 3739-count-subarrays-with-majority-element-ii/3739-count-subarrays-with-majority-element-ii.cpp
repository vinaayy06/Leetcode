class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prev(n*2 +1,0);
        prev[n] = 1;
        int cnt = n;
        long long ans =0,prevsum = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == target){
                prevsum += prev[cnt];
                cnt++;
                prev[cnt]++;
                
            }
            else{
                cnt--;
                prevsum -= prev[cnt];
                prev[cnt]++;
            }
            ans += prevsum;
        }
        return ans;
    }
};