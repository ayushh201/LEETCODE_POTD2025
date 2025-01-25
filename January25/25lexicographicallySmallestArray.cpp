class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> vec=nums;
        sort(begin(vec),end(vec));
        int group=0;
        unordered_map<int,int> NumberToGroup;
        NumberToGroup[vec[0]]=group;
        unordered_map<int,list<int>> GroupToList;
        GroupToList[group].push_back(vec[0]);
        for(int i=1;i<n;i++){
            if(abs(vec[i]-vec[i-1])>limit){
                group++;
            }
            NumberToGroup[vec[i]]=group;
            GroupToList[group].push_back(vec[i]);
        }
        vector<int> result(n);
        for(int i=0;i<n;i++){
            int num=nums[i];
            int group=NumberToGroup[num];
            result[i]=*(GroupToList[group].begin());
            GroupToList[group].pop_front();
        }
        return result;
    }
};
