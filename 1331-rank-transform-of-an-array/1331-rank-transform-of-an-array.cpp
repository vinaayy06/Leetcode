class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> nums;
        for(int i=0;i<n;i++){
            nums[arr[i]].push_back(i);
        }
        int rank =1;
        for(auto & pair: nums){
            for(int j : pair.second){
                arr[j] = rank;
            }
            rank++;
        }
        return arr;
    }
};