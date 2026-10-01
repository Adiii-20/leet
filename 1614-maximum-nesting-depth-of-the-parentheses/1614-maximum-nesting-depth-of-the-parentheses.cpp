class Solution {
public:
    int maxDepth(string s) {
        int front = 0;
        int back = 0;
        int maxi = 0;
        for(int i =0 ; i<s.size() ; i++){
            if(s[i]== '(') {
                front++;
                maxi=max(maxi,front);
            }
            else if( s[i]== ')' ) {
                back++;
                front--;
            }
        }
        return maxi;
    }
};