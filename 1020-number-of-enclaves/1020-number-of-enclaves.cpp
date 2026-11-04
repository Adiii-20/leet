class Solution {
public:

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                grid[0][i]=2;
                q.push({0,i});
            }
            if(grid[n-1][i]==1){
                grid[n-1][i]=2;
                q.push({n-1,i});
            }
        }
        for(int i=1;i<n-1;i++){
            if(grid[i][0]==1){
                grid[i][0]=2;
                q.push({i,0});
            }
            if(grid[i][m-1]==1){
                grid[i][m-1]=2;
                q.push({i,m-1});
            }
        }
        int one=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1) one++;
            }
        }
        while(!q.empty()){
            pair<int,int>p=q.front();
            int row=p.first;
            int col=p.second;
            q.pop();
            if(row-1>=0 && grid[row-1][col] == 1){
                one--;
                grid[row-1][col]=2;
                q.push({row-1,col});
            }
            if(col-1>=0 && grid[row][col-1] == 1){
                one--;
                grid[row][col-1]=2;
                q.push( {row,col-1});
            } 
            if(row+1<grid.size() && grid[row+1][col] == 1){
                 one--;
                 grid[row+1][col]=2;
                 q.push( {row+1,col});
            }
            if(col+1<grid[0].size() && grid[row][col+1] == 1) {
                one--;
                grid[row][col+1]=2;
                q.push( {row,col+1});
            }
        }
        return one;
    }
};