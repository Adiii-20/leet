class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        if(n==1) return true;
        sort(nums1.begin(),nums1.end());
        int indo=1;
        int inde=1;
        if(nums1[0]%2==0){
            while(indo<n && nums1[indo]%2==0) indo++;
            if(indo==n) return true;
            for(int i=1;i<n;i++){
                if(nums1[i]%2!=0 && indo>=i) return false;
            }
        }
        else {
            while(inde<n && nums1[inde]!=0) inde++;
            if(inde==n) return true;
            for(int i=1;i<n;i++){
                if(nums1[i]%2==0 && inde>=i) return false;
            }
        }
        return true;
    }
};