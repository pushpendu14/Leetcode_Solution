/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int low=1;
        int high=x/2;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long val= 1ll * mid*mid;
            if(val>x){
                high=mid-1;
            }else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};
// @lc code=end

