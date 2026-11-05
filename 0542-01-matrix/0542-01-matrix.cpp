class Solution {
public:  

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<pair<int,int>,int>p=q.front();
                int r=p.first.first;
                int c=p.first.second;
                int dis=p.second;

                if( r-1>=0 && visited[r-1][c]!=1){
                    visited[r-1][c]=1;
                    mat[r-1][c]=dis+1;
                    q.push({{r-1,c},dis+1});
                }

                if( r+1<n && visited[r+1][c]!=1){
                    visited[r+1][c]=1;
                    mat[r+1][c]=dis+1;
                    q.push({{r+1,c},dis+1});
                }

                if( c-1>=0 && visited[r][c-1]!=1){
                    visited[r][c-1]=1;
                    mat[r][c-1]=dis+1;
                    q.push({{r,c-1},dis+1});
                }

                if(c+1<m && visited[r][c+1]!=1){
                    visited[r][c+1]=1;
                    mat[r][c+1]=dis+1;
                    q.push({{r,c+1},dis+1});
                }

                q.pop();
            }
        }
        return mat;
    }
};