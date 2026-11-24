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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});

        while (!q.empty()) {
            TreeNode* left = q.front().first;
            TreeNode* right = q.front().second;
            q.pop();

            if (left == nullptr && right == nullptr) continue;
            if (left == nullptr || right == nullptr) return false;

            if (left->val != right->val) return false;

            q.push({left->left, right->right});
            q.push({left->right, right->left});
        }

        return true;
    }
};
