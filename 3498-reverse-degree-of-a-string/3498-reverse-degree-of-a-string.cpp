class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;
        vector<int>arr(26,0);
        int num=26;
        for(int i=0;i<26;i++){
            arr[i]=num;
            num--;
        }
        for(int i=0;i<n;i++){
            sum+= (i+1) * arr[(s[i]-'a')];
        }
        return sum;
    }
};