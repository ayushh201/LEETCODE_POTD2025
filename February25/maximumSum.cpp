class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        int result=-1;
        for(int i=0;i<nums.size();i++){
            if(mp.count(digitSum(nums[i]))){
                result=max(result,nums[i]+mp[digitSum(nums[i])]);
            }
            mp[digitSum(nums[i])]=max(nums[i],mp[digitSum(nums[i])]);
        }
        return result;
    }
};
