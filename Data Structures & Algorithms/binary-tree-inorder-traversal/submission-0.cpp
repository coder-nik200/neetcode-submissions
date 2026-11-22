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
   private:
    void dfd(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;

        dfd(root->left, res);
        res.push_back(root->val);
        dfd(root->right, res);
    }

   public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        dfd(root, res);

        return res;
    }
};