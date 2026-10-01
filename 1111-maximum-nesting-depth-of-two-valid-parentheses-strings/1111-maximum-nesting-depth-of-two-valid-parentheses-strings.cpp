class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int open=0;
        int maxi=INT_MIN;
        vector<int>v(seq.size());
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='(') {
                open++;
                maxi=max(maxi,open);
                v[i]=open;
            }
            else if(seq[i]==')'){
                v[i]=open;
                open--;
            }
        }
        int m=maxi/2;
        for(int i=0;i<seq.size();i++){
            if( m!=0 && v[i]>m) v[i]=1;
            else v[i]=0;
        }
        return v;
    }
};