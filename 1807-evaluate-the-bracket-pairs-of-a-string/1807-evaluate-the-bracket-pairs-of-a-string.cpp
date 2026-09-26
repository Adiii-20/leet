class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map < string , int > mpp ;
        int rows=knowledge.size();
        for( int i = 0 ; i < rows ; i++ ){
            mpp[knowledge[i][0]] = i;
        }
        int end = 0 ;
        int brack = 0 ;
        string ans = "";
        for( int i = s.size()-1; i >=0 ; i--){
            if(s[i] == '('){
                string ref = s.substr( i+1, end-1-i);
                if(mpp.find(ref) != mpp.end()){
                    string st = knowledge[mpp[ref]][1];
                    reverse(st.begin() , st.end());
                    ans += st; 
                }
                else{
                    ans += "?";
                } 
                brack--;
            }
            if( s[i] == ')'){
                brack++;
                end = i;
            }
            if( s[i] != '(' && brack == 0 ) ans += s[i]; 
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};