class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalg=0;
        int totalc=0;
        for(int i=0;i<n;i++){
            totalg+=gas[i];
            totalc+=cost[i];
        }
        if(totalg<totalc) return -1;
        int s=0;
        int cur=0;
        for(int i=0;i<n;i++){
            cur+=gas[i]-cost[i];
            if(cur<0){
                cur=0;
                s=i+1;
            }
        }
        return s;
    }
};