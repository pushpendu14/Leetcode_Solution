class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0;
        int right=0;
        int countzero=0;
        int maxlength=0;

        while(right<nums.size()){

            if(nums[right]==0) countzero++;

            while(countzero>1){
                if(nums[left]==0) countzero--;
                left++;
            }

            maxlength = max(maxlength,right-left);
            right++;
        }
        return maxlength;
    }
};
