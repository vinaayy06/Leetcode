class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        ans.reserve(n + m);
        for(int i=0;i<n;i++){
            ans.push_back(nums1[i]);
        }
        for(int j=0;j<m;j++){
            ans.push_back(nums2[j]);
        }
        sort(ans.begin(),ans.end());
        int v = ans.size();
        if(v==0) return 0.0;
        if(v%2 == 1){
            return (double)ans[v/2];
        } 
        else{
            return (ans[v/2 - 1] + ans[v/2]) / 2.0;
        }        
    }
};