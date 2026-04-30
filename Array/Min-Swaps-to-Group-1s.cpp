class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n=arr.size();
        
        int total_ones=0;
        
        for(int i=0; i<n; i++){
            if(arr[i]==1) total_ones++;
        }
        
        int window_size=total_ones, window_ones=0;
        
        for(int i=0; i<window_size; i++){
            if(arr[i]==1) window_ones++;
        }
        
        int t=window_ones;
        for(int i=window_size,j=0; i<n; i++,j++){
            if(arr[i]==1) window_ones++;
            if(arr[j]==1) window_ones--;
            t= max(t,window_ones);
        }
        int ans = t==0? -1: total_ones-t;
        return ans;
    }
};
