class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> answer(n,0);
        int currentValue=0,currentValueSum=0;
        for(int i=0;i<n;i++){
            answer[i]=currentValueSum;
            currentValue+=boxes[i]=='0'? 0:1;
            currentValueSum+=currentValue;
        }
        currentValue=0,currentValueSum=0;
        for(int i=n-1;i>=0;i--){
            answer[i]+=currentValueSum;
            currentValue+=boxes[i]=='0'? 0:1;
            currentValueSum+=currentValue;
        }
        return answer;
    }
};
