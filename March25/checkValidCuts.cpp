class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        result.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < result.back()[1]){
                //overlap
                result.back()[1]=max(result.back()[1],intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> vertical;
        vector<vector<int>> horizontal;
        for(auto &rectangle : rectangles){
            int x1 = rectangle[0];
            int y1 = rectangle[1];
            int x2 = rectangle[2];
            int y2 = rectangle[3];
            vertical.push_back({x1,x2});
            horizontal.push_back({y1,y2});
        }
        vector<vector<int>> result1 = merge(vertical);
        if(result1.size() >= 3) return true;
        vector<vector<int>> result2 = merge(horizontal);
        return result2.size() >= 3;
    }
};
