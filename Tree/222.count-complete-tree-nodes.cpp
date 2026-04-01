/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 */

// @lc code=start
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
    int leftheight(TreeNode * root){
        int h=0;
        while(root){
            h++;
            root=root->left;
        }
        return h;
    }
    int rightheight(TreeNode * root){
        int h=0;
        while(root){
            h++;
            root=root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh,rh;
        lh=leftheight(root);
        rh=rightheight(root);
        if(lh==rh) return pow(2,lh)-1;
        return 1+ countNodes(root->left)+countNodes(root->right);
    }
};
// @lc code=end

