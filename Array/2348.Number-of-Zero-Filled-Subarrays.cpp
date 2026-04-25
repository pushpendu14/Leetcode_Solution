class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum=0;
        int countzeroes=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                sum += countzeroes+1;
                countzeroes++;
            }else {
                countzeroes=0;
            }
        }
        return sum;
    }
};
