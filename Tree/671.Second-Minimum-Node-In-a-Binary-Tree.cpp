/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int min1;
    long long min2 = LLONG_MAX;

    void dfs(TreeNode * root){
        if(!root) return;
        if(root->val > min1 && root->val < min2){
            min2 = root->val;
        }
        dfs(root->left);
        dfs(root->right);

    }
    int findSecondMinimumValue(TreeNode* root) {
        
        if(!root) return -1;
        min1=root->val;
        dfs(root);
        return min2==LLONG_MAX ? -1:(int)min2;
    }
};
