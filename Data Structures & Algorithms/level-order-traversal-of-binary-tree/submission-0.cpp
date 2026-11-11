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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int levelsize = q.size();
            vector<int> level;
            for(int i = 0; i < levelsize;++i){
                TreeNode* top;
                top = q.front();
                if(top->left != nullptr){
                    q.push(top->left);
                }
                if(top->right != nullptr){
                    q.push(top->right);
                }
                level.push_back(top->val);
                q.pop();
            }
            ans.push_back(level);
        }
        return ans;
    }
};
