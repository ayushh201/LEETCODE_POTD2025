class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int> mp;
        vector<int> result;
        for(int i=0;i<s.length();i++){
            mp[s[i]-'a']=i;
        }
        int n = s.length();
        int start=0, end=0, i=0;
        while(i < n){
            end = max(end,mp[s[i]-'a']);
            if(i == end){
                result.push_back(end-start+1);
                start=end+1;
            }
            i++;
        }
        return result;
    }
};
