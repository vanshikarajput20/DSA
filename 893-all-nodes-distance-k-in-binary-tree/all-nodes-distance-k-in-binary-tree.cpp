/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp, int k){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }

        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        parent(root, mp, k);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr = 0;

        while(!q.empty()){
            int size = q.size();
            if(curr++ == k) break;

            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(mp[node] && !visited[mp[node]]){
                    visited[mp[node]] = true;
                    q.push(mp[node]);
                }
            }
        }
        vector<int> result;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
            
        }
        return result;

    }
};