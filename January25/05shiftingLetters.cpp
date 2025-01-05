class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diff(s.length(),0);
        for(auto shift:shifts){
            int l=shift[0];
            int r=shift[1];
            int dir=shift[2];
            int x;
            if(dir==0){
                x=-1;
            }else{
                x=1;
            }
            diff[l]+=x;
            if(r+1<s.length()){
                diff[r+1]-=x;
            }
        }
        for(int i=1;i<s.length();i++){
            diff[i]+=diff[i-1];
        }
        for(int i=0;i<s.length();i++){
            int shift=diff[i]%26;
            if(shift<0) shift+=26;
            s[i]=((s[i]-'a'+shift)%26)+'a';
        }
        return s;
    }
};
