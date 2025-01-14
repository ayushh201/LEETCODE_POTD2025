class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<int> result(n);
        vector<int> freq(n+1,0);
        int count=0;
        for(int i=0;i<n;i++){
            freq[a[i]]++;
            if(freq[a[i]]==2) count++;
            freq[b[i]]++;
            if(freq[b[i]]==2) count++;
            result[i]=count;
        }
        return result;
    }
};
