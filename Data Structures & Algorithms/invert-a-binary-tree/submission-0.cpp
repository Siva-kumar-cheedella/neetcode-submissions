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
    void swapLR(TreeNode* node){
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    void postOrderTraversal(TreeNode* root){
        if(root==nullptr) return;
        swapLR(root);
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        postOrderTraversal(root);
        return root;
    }
};
