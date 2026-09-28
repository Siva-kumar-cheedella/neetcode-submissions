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
    bool checkIfTreesAreSame(TreeNode* p, TreeNode* q){
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr || p->val != q->val) return false;
        return checkIfTreesAreSame(p->left, q->left) && checkIfTreesAreSame(p->right, q->right);
    }

    bool traverseTree(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr) return false;
        
        return checkIfTreesAreSame(root, subRoot) || traverseTree(root->left, subRoot) || traverseTree(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return traverseTree(root, subRoot);
    }
};
