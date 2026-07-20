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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
        stack<TreeNode *>st;
        if(root){
            st.push(root);
        }

        while(!st.empty()){
            TreeNode *s = st.top();
            st.pop();
            result.push_back(s->val);

            if(s->right){
                st.push(s->right);
            }
            if(s->left){
                st.push(s->left);
            }
        }
        return result;
    }
};
