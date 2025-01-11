class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        //edge cases
        if(n<k) return false;
        if(n==k) return true;
        vector<int> freq(26,0);
        for(char &ch:s){
            freq[ch-'a']++;
        }
        int oddFrequencyCount=0;
        for(int i=0;i<26;i++){
            if(freq[i]%2!=0){
                oddFrequencyCount++;
            }
        }
        return oddFrequencyCount<=k;
    }
};
