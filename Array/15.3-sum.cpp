/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size()-2; i++){
            int l=i+1;
            int h=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(l<h){
                int sum=nums[i]+nums[l]+nums[h];
                if(sum==0){
                    ans.push_back({nums[i],nums[l],nums[h]});
                    l++;
                    h--;
                    while(l<h && nums[l]==nums[l-1]) l++;
                    while(l<h && nums[h]==nums[h+1]) h--;
                }else if(sum<0){
                    l++;
                }else{
                    h--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

