class Solution {
public:
    string smallestNumber(string pattern) {
        string res="";
        int n=pattern.length();
        stack<int> st;
        for(int i=1;i<=n+1;i++){
            st.push(i);
            if(i==n+1 || pattern[i-1]=='I'){
                while(!st.empty()){
                    res.push_back(char('0'+st.top()));
                    st.pop();
                }
            }
        }
        return res;
    }
};
