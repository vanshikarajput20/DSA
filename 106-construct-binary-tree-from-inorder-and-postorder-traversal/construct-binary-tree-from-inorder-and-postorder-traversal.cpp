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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return nullptr;
        map<int, int> mpp;

        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* tree = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mpp);
        return tree;
    }

    TreeNode* build(vector<int>& postorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int,int>& mpp){
        if(ps > pe || is > ie) return nullptr;

        TreeNode* root = new TreeNode(postorder[pe]);
        int rootId = mpp[root->val];
        int nums = rootId - is;

        root->left = build(postorder, ps, ps + nums - 1, inorder, is, rootId - 1, mpp);
        root->right = build(postorder, ps + nums , pe - 1, inorder, rootId + 1, ie, mpp);
        return root;
    }
};