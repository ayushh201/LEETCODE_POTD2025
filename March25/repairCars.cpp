class Solution {
public:
    int n;
    typedef long long ll;
    bool isPossible(vector<int>& ranks, int cars,ll mid){
        ll totalCars=0;
        for(int i=0;i<n;i++){
            totalCars += sqrt(mid/ranks[i]);
        }
        return totalCars>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        n=ranks.size();
        ll l=1;
        int maxC=*max_element(begin(ranks),end(ranks));
        ll r=1LL*maxC*cars*cars;
        ll result=-1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(isPossible(ranks,cars,mid)){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }
};
