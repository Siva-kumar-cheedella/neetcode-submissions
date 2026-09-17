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

    int traverseTree(TreeNode* root, int& diameter){
        if(root==nullptr)return 0;

        int maxLeftDepth = traverseTree(root->left, diameter);
        int maxRightDepth = traverseTree(root->right, diameter);

        diameter = max(diameter, maxLeftDepth+maxRightDepth);
        return 1+max(maxLeftDepth, maxRightDepth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        traverseTree(root, diameter);
        return diameter;
    }
};
