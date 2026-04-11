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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        while(!node_queue.empty()) {
            TreeNode* temp = node_queue.front();
            result.push_back(temp->val);
            int size = node_queue.size();
            for (int i = 0; i<size; i++) {
                TreeNode* temp = node_queue.front();
                node_queue.pop();
                if (temp->right) {
                    node_queue.push(temp->right);
                }
                if (temp->left) {
                    node_queue.push(temp->left);
                }
            }
        }
        return result;
    }
};