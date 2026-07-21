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
    bool isUnivalTree(TreeNode* root) {
        if(root==nullptr) return true;

        int same=root->val;
        if(root->left != nullptr && root->left->val != same) return false;
        if(root->right != nullptr && root->right->val != same) return false;

        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
