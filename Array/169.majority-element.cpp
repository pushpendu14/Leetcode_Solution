/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int ,int>mp;
        int ans=-1;

        for(int x : nums){
            mp[x]++;
        }

        for(auto x : mp){
            if(x.second >n/2) ans=x.first;
        }
        return ans;
    }
};
// @lc code=end

