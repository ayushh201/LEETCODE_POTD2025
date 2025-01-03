class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long totalSum=0;
        for(int &num:nums){
            totalSum+=num;
        }
        long long leftSum=0, rightSum=0;
        int count=0;
        for(int i=0;i<n-1;i++){
            leftSum+=nums[i];
            rightSum=totalSum-leftSum;
            if(leftSum>=rightSum){
                count++;
            }
        }
        return count;
    }
};
