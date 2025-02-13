class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int countOperations=0;
        priority_queue<long,vector<long>,greater<long>> pq(begin(nums),end(nums)); //heapify - total operation of log n
        //for(&num:nums) {
            //pq.push(num) -> log n
        //}
        //overall -> nlog n(avoid)
        while(!pq.empty() && pq.top()<k){ //n
            long smallest=pq.top();
            pq.pop(); //logn
            long secondSmallest=pq.top();
            pq.pop(); //log n;
            pq.push(smallest*2 + secondSmallest); //log n
            countOperations++;
        }
        return countOperations;
        //overall -> n*(3 log n) -> nlogn
    }
};
