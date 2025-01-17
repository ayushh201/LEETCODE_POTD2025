class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> a(n,0);
        a[0]=0;
        for(int i=0;i<n-1;i++){
            a[i+1]=a[i]^derived[i];
        }
        if(a[n-1]^a[0]==derived[n-1]) return true;
        a[0]=1;
        for(int i=0;i<n-1;i++){
            a[i+1]=a[i]^derived[i];
        }
        if(a[n-1]^a[0]==derived[n-1]) return true;
        return false;
    }
};
