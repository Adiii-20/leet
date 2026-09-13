class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector< pair<int,int> >one;
        vector< pair<int,int> > two;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( img1[i][j]==1 ) one.emplace_back(i,j);
                if( img2[i][j]==1 ) two.emplace_back(i,j);
            }
        }
        vector<vector<int>> c(2 * n, vector<int>(2 * n, 0));
        int ans = 0;
        for (auto& a : one) {
            for (auto& b : two) {
                int x = b.first - a.first + n;
                int y = b.second - a.second + n;
                ans = max(ans, ++c[x][y]);
            }
        }
        return ans;
    }
};