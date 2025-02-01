class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]%2 == nums[i+1]%2){
                return false;
            }
        }
        return true;
    }
};


//Variation - 3152. Special Array II
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> cumulativeSum(n,0);
        cumulativeSum[0]=0;
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                cumulativeSum[i]=cumulativeSum[i-1]+1;
            }else{
                cumulativeSum[i]=cumulativeSum[i-1];
            }
        }
        vector<bool> result(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];
            if(cumulativeSum[end]-cumulativeSum[start]==0){
                result[i]=true;
            }
        }
        return result;
    }
};
