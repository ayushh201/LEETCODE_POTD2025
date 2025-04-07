class Solution {
public:
    int t[201][20001];
    bool solve(vector<int>& nums,int i,int target){
        if(target==0) return true;
        if(i>=nums.size()) return false;
        if(t[i][target]!=-1) return t[i][target];
        bool skip = solve(nums,i+1,target);
        bool take = false;
        if(nums[i]<=target){
            take = solve(nums,i+1,target-nums[i]);
        }
        return t[i][target] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        memset(t,-1,sizeof(t));
        for(int num : nums) totalSum+=num;
        if(totalSum % 2) return false;
        return solve(nums,0,totalSum/2);
    }
};
