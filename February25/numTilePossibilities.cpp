class Solution {
    private:
    void solve(string &tiles, vector<bool> &used, unordered_set<string> &result, string &curr){
        result.insert(curr);
        for(int i=0;i<tiles.size();i++){
            if(used[i]) continue;
            //explore
            used[i]=true;
            curr.push_back(tiles[i]);
            solve(tiles,used,result,curr);
            //backtrack
            used[i]=false;
            curr.pop_back();
        }
    }
public:
    int numTilePossibilities(string tiles) {
        int n=tiles.length();
        unordered_set<string> result;
        vector<bool> used(n,false);
        string curr="";
        solve(tiles,used,result,curr);
        return result.size()-1;
    }
};
