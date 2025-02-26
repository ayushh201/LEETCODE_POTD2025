class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int maxSubarraySum=nums[0];
        int currSubarraySum=nums[0];
        for(int i=1;i<n;i++){
            currSubarraySum=max(nums[i],currSubarraySum+nums[i]);
            maxSubarraySum=max(maxSubarraySum,currSubarraySum);
        }
        int minSubarraySum=nums[0];
        currSubarraySum=nums[0];
        for(int i=1;i<n;i++){
            currSubarraySum=min(nums[i],currSubarraySum+nums[i]);
            minSubarraySum=min(minSubarraySum,currSubarraySum);
        }
        return max(abs(minSubarraySum),abs(maxSubarraySum));
    }
};
