class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        map<int,int> mp;
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            int id=nums1[i][0];
            int value=nums1[i][1];
            mp[id]+=value;
        }
        for(int i=0;i<m;i++){
            int id=nums2[i][0];
            int value=nums2[i][1];
            mp[id]+=value;
        }
        for(auto &it:mp){
            int key=it.first;
            int value=it.second;
            result.push_back({key,value});
        }
        return result;
    }
};
