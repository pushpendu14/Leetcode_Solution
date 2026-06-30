class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int t_sum=0;
        for(int i=1; i<=n; i++){
            t_sum += i;
        }
        int a_sum=0;
        for(int i=0; i<n; i++){
            a_sum+=nums[i];
        }

        return t_sum-a_sum;
    }
};
