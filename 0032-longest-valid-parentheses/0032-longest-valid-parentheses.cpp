class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size() ;
        int maxi = INT_MIN ;
        stack <int> st ;
        st.push( -1 ) ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == ')'){
                st.pop() ; 
               if( !st.empty() ) maxi = max( maxi , i - st.top() );
               else {
                st.push( i ) ;
               }
            }
            else st.push( i ) ;
        }
        return maxi == INT_MIN ? 0 : maxi ;
    }
};