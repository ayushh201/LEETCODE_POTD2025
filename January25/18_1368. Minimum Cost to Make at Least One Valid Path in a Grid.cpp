class Solution {
public:
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    int minCost(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        pq.push({0,0,0});
        result[0][0]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            int currCost=curr[0];
            int i=curr[1];
            int j=curr[2];

            if(currCost>result[i][j]){
                continue;
            }
            
            for(int k=0;k<=3;k++){
                int di=i+directions[k][0];
                int dj=j+directions[k][1];

                if(di>=0 && di<m && dj>=0 && dj<n){
                    int gridDir=grid[i][j];
                    int gridCost=((gridDir-1!=k)? 1:0);
                    int newCost=currCost+gridCost;

                    if(newCost<result[di][dj]){
                        result[di][dj]=newCost;
                        pq.push({newCost,di,dj});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};
