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
    vector<int> inorderTraversalRecursive(TreeNode* root, vector<int>& output){
        if (root==nullptr) {
            return output;
        }

        inorderTraversalRecursive(root->left, output);
        output.push_back(root->val);
        inorderTraversalRecursive(root->right, output);
        return output;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        return inorderTraversalRecursive(root, output);
    }
};