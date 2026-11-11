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
    int count = 0;
    int answer = 0;

    void inorder(TreeNode* node, int k) {
        if (!node) return;

        // TODO 1: 左子樹
        inorder(node->left, k);
        // TODO 2: 更新 count
        count++;
        // TODO 3: 如果 count == k，記錄 answer
        if(count == k){
            answer = node->val;
        }
        // TODO 4: 右子樹
        inorder(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return answer;
    }
};
