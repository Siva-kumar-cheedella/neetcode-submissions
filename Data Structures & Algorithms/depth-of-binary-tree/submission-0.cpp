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

    int traverseTree(TreeNode* root){
        if(root == nullptr) return 0;
        int maxLeftDep = traverseTree(root->left);
        int maxRightDep = traverseTree(root->right);
        return 1 + max(maxLeftDep, maxRightDep);
    }

    int maxDepth(TreeNode* root) {
        return traverseTree(root);
    }
};
