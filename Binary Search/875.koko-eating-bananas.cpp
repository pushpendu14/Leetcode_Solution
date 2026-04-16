/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    long long calculateTime(vector<int> &arr, long long k){
        long long time=0;
        for(int i=0; i<arr.size(); i++){
            time += ceil(double(arr[i])/double(k));
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max=INT_MIN;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]>max) max=piles[i];
        }
        int i=1;
        int j=max;
        int ans;
        while(i<=j){
            long long mid =i+(j-i)/2;
            long long k =calculateTime(piles,mid);
            if(k<=h){
                j=mid-1;
                ans=mid;
            }else {
                i=mid+1;
            }
        }
        return ans;
        
    }
};
// @lc code=end

