class Solution {
public:

    bool bfs(vector<vector<int>>& grid, int i, int j ){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0) return false;
        if(grid[i][j]==1) return true;
        grid[i][j]=1;
        return bfs(grid,i+1,j) & bfs(grid,i,j+1) & bfs(grid,i-1,j) & bfs(grid,i,j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) {
                    if(bfs(grid,i,j)) count++;
                }
            }
        }
        return count;
    }
};