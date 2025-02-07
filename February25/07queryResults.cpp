class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        unordered_map<int,int> ballColor;
        unordered_map<int,int> colorFreq;
        vector<int> result(n);
        for(int i=0;i<n;i++){
            int ball = queries[i][0];
            int color = queries[i][1];
            if(ballColor.count(ball)){
                colorFreq[ballColor[ball]]--;
                if(colorFreq[ballColor[ball]]==0){
                    colorFreq.erase(ballColor[ball]);
                }                                 
            }
            ballColor[ball]=color;
            colorFreq[ballColor[ball]]++;
            result[i]=colorFreq.size();
        }
        return result;
    }
};
