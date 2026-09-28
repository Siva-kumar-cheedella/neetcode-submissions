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
    TreeNode* lca=nullptr;
    bool traverseAndFindLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr)return false;
        bool isAnyPresentLeft = traverseAndFindLCA(root->left, p, q);
        bool isAnyPresentRight = traverseAndFindLCA(root->right, p, q);
        
        bool canRootBeLCA = false;
        
        if(root->val == p->val || root->val == q->val) canRootBeLCA = true;
        
        if(canRootBeLCA){
            if(isAnyPresentLeft || isAnyPresentRight) lca = root;
            return true;
        }else{
            if(isAnyPresentLeft && isAnyPresentRight){
                lca = root;  
                return true;
            } 
        }
        return isAnyPresentLeft || isAnyPresentRight;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverseAndFindLCA(root, p, q);
        return lca;
    }
};
