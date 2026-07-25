class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =nums.size();
        int can = nums[0];
        int count=1;

        for(int i=1; i<n; i++){
            if(nums[i] == can) count++;
            else count--;

            if(count == 0){
                can = nums[i];
                count = 1;
            }            
        }
        int occurence=0;
        for(int x : nums){
            if(x==can) occurence++;
        }
        return occurence >= n/2+1 ? can : -1;
    }
};
