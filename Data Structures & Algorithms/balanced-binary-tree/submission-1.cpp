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
    int dfs(TreeNode* node) {
    if (node == nullptr) return 0;

    int leftDepth = dfs(node->left);

    if (leftDepth < 0 ){
        return -1;
    }
    int rightDepth = dfs(node->right);

    if (rightDepth < 0 ){
        return -1;
    }
    if (abs(leftDepth - rightDepth) > 1){
        return -1;
    }
    return 1 + max(leftDepth, rightDepth);
}
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;

    }
};
