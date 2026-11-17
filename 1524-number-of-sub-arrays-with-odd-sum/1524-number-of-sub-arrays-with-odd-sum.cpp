class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        int odd=0;
        int even=1;
        int mod=1e9+7;
        int ans=0;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            if(sum%2==0){
                ans=(ans+odd)%mod;
                even++;
            }
            else {
                ans=(ans+even)%mod;
                odd++;
            }
        }
        return ans;
    }
};