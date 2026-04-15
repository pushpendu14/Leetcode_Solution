/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p=0;
        int q=0;
        int r=nums.size()-1;

        while(q<=r){
            if(nums[q]==0){
                swap(nums[p],nums[q]);
                p++;
                q++;
            }else if(nums[q]==1){
                q++;
            }else{
                swap(nums[r],nums[q]);
                r--;
            }
        }
    }
};
// @lc code=end

