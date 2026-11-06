class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vec(numCourses,0);
        int n=prerequisites.size();
        vector<vector<int>>edge(numCourses);
        for(int i=0; i<n; i++){
            vec[prerequisites[i][0]]++;
            edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<numCourses;i++){
            if(vec[i]==0){
                q.push(i);
                topo.push_back(i);
            }
        }
        while( !q.empty() ){
            int ind=q.front();
            q.pop();
            int s = edge[ind].size();
            for(int i=0;i<s;i++){
                vec[edge[ind][i]]--;
                if(vec[edge[ind][i]]==0){
                    topo.push_back( edge[ind][i] );
                    q.push(edge[ind][i]);
                }
            }
        }
        if(topo.size()==numCourses) return true;
        return false;
    }
};