class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        vector<int> indices;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                indices.push_back(i);
                if(indices.size()>2) return false;
            }
        }
        if(indices.size()==0) return true;
        if(indices.size()==2){
            int i=indices[0];
            int j=indices[1];
            return s1[i]==s2[j] && s1[j]==s2[i];
        }
        return false;
    }
};
