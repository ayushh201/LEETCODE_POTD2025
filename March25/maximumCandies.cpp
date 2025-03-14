class Solution {
public:
    bool canDistribute(vector<int>& candies, long long k,int mid){
        int n=candies.size();
        long long count=0;
        for(int i=0;i<n;i++){
            count+=(candies[i]/mid);
            if(count>=k) return true;
        }
        return count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        long long total=0;
        int maxC=INT_MIN;
        for(int c:candies){
            total+=c;
            maxC=max(maxC,c);
        }
        if(total<k){
            return 0;
        }
        int l=1,r=maxC;
        int result=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canDistribute(candies,k,mid)){
                result=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return result;
    }
};
