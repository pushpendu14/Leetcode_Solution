/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */

// @lc code=start
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int total_ones=0, n= nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==1) total_ones++;
        }
        if(total_ones==0 || total_ones==n) return 0;
        int window_ones=0, maxcount=0;
        for(int i=0; i<total_ones; i++){
            if(nums[i]==1) window_ones++;
        }
        maxcount = window_ones;
        int end=total_ones;
        for(int i=0; i<n; i++){
            if(nums[end]==1) window_ones++;
            if(nums[i]==1) window_ones--;
            maxcount = max(maxcount, window_ones);
            end = (end+1)%n;
        }

        return (total_ones - maxcount);
    }
};
// @lc code=end

