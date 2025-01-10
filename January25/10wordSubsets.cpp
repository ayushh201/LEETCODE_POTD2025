class Solution {
public:
    bool isSubset(vector<int> &temp,vector<int> &freq){
        for(int i=0;i<26;i++){
            if(temp[i]<freq[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> freq(26,0);
        for(string &word:words2){
            int temp[26]={0};
            for(char &ch:word){
                temp[ch-'a']++;
                freq[ch-'a']=max(freq[ch-'a'],temp[ch-'a']);
            }
        }
        for(string &word:words1){
            vector<int> temp(26,0);
            for(char &ch:word){
                temp[ch-'a']++;
            }
            if(isSubset(temp,freq)==true){
                result.push_back(word);
            }
        }
        return result;
    }
};
