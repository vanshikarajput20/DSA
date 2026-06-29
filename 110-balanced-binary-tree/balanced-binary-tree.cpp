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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = maxDepth(root->left);
        if(lh == -1) return -1;
        int rh = maxDepth(root->right);
        if(rh == -1) return -1;

        if(abs(lh-rh) > 1) return -1;
        
        int maxi = max(lh, rh);
        return 1 + maxi ;
    }

    bool isBalanced(TreeNode* root) {
        return (maxDepth(root) != -1);
    }
};