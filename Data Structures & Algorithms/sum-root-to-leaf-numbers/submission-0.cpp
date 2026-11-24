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
    void sumNum(TreeNode* root, int num, int& sum) {
        if (root == nullptr) return;

        num = num * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            sum += num;
            return;
        }

        sumNum(root->left, num, sum);
        sumNum(root->right, num, sum);
    }

   public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumNum(root, 0, sum);

        return sum;
    }
};