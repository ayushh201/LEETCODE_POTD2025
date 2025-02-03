class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength=1, inc=1,dec=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
                dec=1;
            }else if(nums[i]<nums[i-1]){
                dec++;
                inc=1;
            }else{
                inc=1;
                dec=1;
            }
            maxLength=max({maxLength,inc,dec});
        }
        return maxLength;
    }
};
