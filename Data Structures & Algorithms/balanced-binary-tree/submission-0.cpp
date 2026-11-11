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

    // TODO 1：如果左子樹不平衡，直接回傳 -1
    if (leftDepth < 0 ){
        return -1;
    }
    int rightDepth = dfs(node->right);

    // TODO 2：如果右子樹不平衡，直接回傳 -1
    if (rightDepth < 0 ){
        return -1;
    }
    // TODO 3：如果左右高度差 > 1，回傳 -1
    if (abs(leftDepth - rightDepth) > 1){
        return -1;
    }


    return 1 + max(leftDepth, rightDepth);
}
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;

    }
};
