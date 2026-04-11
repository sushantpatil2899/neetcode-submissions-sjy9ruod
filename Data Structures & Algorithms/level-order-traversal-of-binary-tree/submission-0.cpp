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
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        queue<TreeNode*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            vector<int> temp;
            int count = node_queue.size();
            for (int i = 0; i<count; i++){
                TreeNode* temp_node = node_queue.front();
                node_queue.pop();
                temp.push_back(temp_node->val);
                if (temp_node->left) {
                    node_queue.push(temp_node->left);
                }
                if (temp_node->right) {
                    node_queue.push(temp_node->right);
                }
            }
            result.push_back(temp);
        }

        return result;
    }
};