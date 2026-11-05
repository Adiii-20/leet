class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m=arr2.size();
        sort(arr2.begin(), arr2.end());
        int count=n;
        for(int i=0;i<n;i++){
            int low = 0;
            int high = m-1;
            while(low<=high ){
                int mid = (low+high)/2;
                if(arr2[mid]>arr1[i]) high=mid-1;
                else low=mid+1;
            }
            if(high>=0 && arr1[i]-arr2[high]<=d) count--;
            else if(low<m && arr2[low]-arr1[i]<=d) count--;
        }
        return count;
    }
};