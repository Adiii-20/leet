class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(costBoth >= (cost1+cost2) ){
            return 1LL* cost1*need1 + 1LL* cost2*need2;
        }
        
        if(need1==0) return 1LL* min(costBoth,cost2)*need2;
        if(need2==0) return 1LL* min(costBoth,cost1)*need1; 
        long long ans=1LL * costBoth*max(need2,need1);

        if( need1<=need2 ){
            long long mini = 1LL* need1*costBoth + 1LL* (need2-need1)*cost2;
            return mini<ans?mini:ans;
        }

        else{
            long long mini = 1LL* need2*costBoth + 1LL* (need1-need2)*cost1;
            return mini<ans?mini:ans;
        }
        return ans;
    }
};