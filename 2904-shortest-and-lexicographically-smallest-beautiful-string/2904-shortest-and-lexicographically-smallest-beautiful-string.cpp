class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++){
            c+=s[i]-'0';
        }
        if(c<k) return "";
        c=0;
        int j=0;
        string ans=s;
        for(int i=0;i<n;i++){
            c+=s[i]-'0';
            while(c>k || s[j]=='0'){
                if(s[j]=='1') c--;
                j++;
            }
            if(c==k){
                string t=s.substr(j,i-j+1);
                if(t.size()<ans.size() || (t.size()==ans.size() && t<ans))
                    ans=t;
            } 
        }
        return ans;
    }
};