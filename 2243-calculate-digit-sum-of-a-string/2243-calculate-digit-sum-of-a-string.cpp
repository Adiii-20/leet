class Solution {
public:
    string digitSum(string s, int k) {
        string ans=s;
        while(ans.size()>k){
            int sum=0;
            string dummy="";
        for(int i=0;i<ans.size();i++){
            sum=sum+ans[i]-'0';
            if( (i+1)%k==0 || i==ans.size()-1){
                dummy = dummy + to_string(sum);
                sum=0;
            } 
        }
        ans=dummy;
        }
        return ans;
    }
};