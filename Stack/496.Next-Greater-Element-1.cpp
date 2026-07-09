class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> ans;
        for(int i=nums2.size()-1; i>=0;i--){
            while(!ans.empty() && ans.top()<=nums2[i]) ans.pop();

            if(ans.empty()){
                map[nums2[i]]=-1;
                ans.push(nums2[i]);
            }else{
                map[nums2[i]]=ans.top();
            }
            ans.push(nums2[i]);
        }
        for(int i=0; i<nums1.size(); i++){
            nums1[i]=map[nums1[i]];
        }
        return nums1;
    }
};
