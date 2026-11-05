class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='X') visited[i][j]=1;
                if( (i==0 || i==n-1 || j==0 || j==m-1 ) && visited[i][j]==0){
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int>p=q.front();
                q.pop();
                int r=p.first;
                int c=p.second;
                if( r-1>=0 && visited[r-1][c]!=1){
                    visited[r-1][c]=1;
                    q.push({r-1,c});
                }

                if( r+1<n && visited[r+1][c]!=1){
                    visited[r+1][c]=1;
                    q.push({r+1,c});
                }

                if( c-1>=0 && visited[r][c-1]!=1){
                    visited[r][c-1]=1;
                    q.push({r,c-1});
                }

                if(c+1<m && visited[r][c+1]!=1){
                    visited[r][c+1]=1;
                    q.push({r,c+1});
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==0) board[i][j]='X';
            }
        }
    }
};