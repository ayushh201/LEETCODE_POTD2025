class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(string &word:words){ //O(n)
            if(word.find(pref)==0){ //O(m)
                count++;
            }
        }
        //TC->O(m*n)
        return count;
    }
};
