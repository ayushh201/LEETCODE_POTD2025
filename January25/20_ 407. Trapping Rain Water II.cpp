class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    int trapRainWater(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int row=0;row<m;row++){
            for(int col:{0,n-1}){
                pq.push({arr[row][col],{row,col}});
                visited[row][col]=true;
            }
        }
        for(int col=0;col<n;col++){
            for(int row:{0,m-1}){
                pq.push({arr[row][col],{row,col}});
                visited[row][col]=true;
            }
        }
        int water=0;
        while(!pq.empty()){
            P it=pq.top();
            pq.pop();

            int height=it.first;
            int i=it.second.first;
            int j=it.second.second;

            for(vector<int> &dir:directions){
                int di=i+dir[0];
                int dj=j+dir[1];
                if(di>=0 && di<m && dj>=0 && dj<n && !visited[di][dj]){
                    water+=max(height-arr[di][dj],0);
                    pq.push({max(height,arr[di][dj]),{di,dj}});
                    visited[di][dj]=true;
                }
            }
        }
        return water;
    }
};
