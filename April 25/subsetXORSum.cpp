class Solution {
public:
    vector<vector<int>> subsets;
    void solve(vector<int> &nums,int i,vector<int> &currSubset){
        if(i==nums.size()){
            subsets.push_back(currSubset);
            return;
        }
        currSubset.push_back(nums[i]);
        solve(nums,i+1,currSubset);
        currSubset.pop_back();
        solve(nums,i+1,currSubset);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> currSubset;
        solve(nums,0,currSubset);
        int result=0;
        for(vector<int> &subset:subsets){
            int Xor=0;
            for(int &num:subset){
                Xor^=num;
            }
            result+=Xor;
        }
        return result;
    }
};
