class Solution {
public:
    #define ll long long
    long long countBadPairs(vector<int>& nums) {
        ll n=nums.size();
        ll gp=0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            if(freq.count(nums[i]-i)){
                gp+=freq[nums[i]-i];
            }
            freq[nums[i]-i]++;
        }
        ll bp=n*(n-1)/2-gp;
        return bp;
    }
};
