class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2!=0){
            return false;
        }
        stack<int> open;
        stack<int> openClose;
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                openClose.push(i);
            }else if(s[i]=='('){
                open.push(i);
            }else if(s[i]==')'){ //locked close->find open
                if(!open.empty()){
                    open.pop();
                }else if(!openClose.empty()){
                    openClose.pop();
                }else{
                    return false;
                }
            }
        }
        while(!openClose.empty() && !open.empty() && open.top()<openClose.top()){
            open.pop();
            openClose.pop();
        }
        return open.empty();
    }
};
