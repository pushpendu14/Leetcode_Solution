/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high =n- 1;
        int ans=-1;
        while(low<=high){
           int mid=(low+high)/2;
            if(nums[mid]==target){
                ans = mid;
                break;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
// @lc code=end

