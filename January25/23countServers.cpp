class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int communicableServersCount = 0;

        vector<int> rowCount(m,0);
        vector<int> colCount(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (rowCount[i]>1 || colCount[j]>1)){
                    communicableServersCount++;
                }
            }
        }

        return communicableServersCount;
    }
};
