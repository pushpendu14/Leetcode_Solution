/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg, currSum=0.0;
        int n=nums.size();
        for(int i=0; i<k; i++){
            currSum +=nums[i];
        }
        maxAvg=currSum/k;
        currSum=currSum/k;

        for(int i=k,j=0; i<n; i++,j++){
            currSum += nums[i]/double(k) - nums[j]/(double)k;
            maxAvg=max(maxAvg,currSum);
        }

        return maxAvg;
    }
};
// @lc code=end

