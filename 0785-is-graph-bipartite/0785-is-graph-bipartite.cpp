class Solution {
public:

    bool dfs( vector<vector<int>>& graph , vector<int>& visit , int ind ){
        int s = graph[ind].size();
        for(int i=0;i<s;i++){
            if( visit[graph[ind][i]] == -1 ){
                    visit[graph[ind][i]] = 1-visit[ind];
                    if(!dfs(graph,visit,graph[ind][i])) return false;
            }
            else {
                if(visit[ graph[ind][i] ] == visit[ind]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visit(n,-1);
        for(int i=0;i<n;i++){
            if(visit[i]==-1){
                visit[i]=1;
                if(!dfs(graph,visit,i)) return false;
            }
        }
       return true;
    }
};