class Solution {
    private:
    int nc2(int n){
        return n*(n-1)/2;
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int count=0;
        for(auto &it:mp){
            if(it.second>1){
                count+=8*nc2(it.second);
            }
        }
        return count;
    }
};
