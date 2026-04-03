/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int curr=0;

        for(auto a: nums){
            curr +=a;
            maxSum = max(curr,maxSum);
            if(curr<0) curr=0;
        }
        return maxSum;
    }
};
// @lc code=end

