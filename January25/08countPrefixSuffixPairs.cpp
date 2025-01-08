class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& str) {
        int n=str.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((str[j].find(str[i])==0) && (str[j].rfind(str[i])==str[j].size()-str[i].size())){
                    count++;
                }
            }
        }
        return count;
    }
};
