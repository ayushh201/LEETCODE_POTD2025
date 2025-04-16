class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long pairs = 0, result = 0;
        unordered_map<int,int> mp;
        int i = 0, j = 0;
        while(j < nums.size()){
            pairs += mp[nums[j]];
            mp[nums[j]]++;
            while(pairs >= k){
                result += (nums.size()-j);
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }
            j++;
        }
        return result;
    }
};
