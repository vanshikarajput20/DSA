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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int, int>>> q;
        q.push({root,{0, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int x = it.second.first;
            int y = it.second.second;

            TreeNode* temp = it.first;
            mp[x][y].insert(temp->val);

            if(temp->left){
                q.push({temp->left, {x-1, y+1}});
            }
            if(temp->right){
                q.push({temp->right, {x+1, y+1}});
            }
        }

        for(auto p : mp){
            vector<int> col;
            for(auto it : p.second){
                col.insert(col.end(), it.second.begin(), it.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};