class Solution {
    private:
    bool isVowel(char &ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        int q=queries.size();
        int sum=0;
        vector<int> cumulativeSum(n,0);
        for(int i=0;i<n;i++){
            if(isVowel(words[i][0]) && isVowel(words[i].back())){
                sum++;
            }
            cumulativeSum[i]=sum;
        }
        vector<int> result(q);
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            result[i]=cumulativeSum[r]-((l>0)? cumulativeSum[l-1]:0);
        }
        return result;
    }
};
