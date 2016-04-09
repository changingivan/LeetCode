// Time:  O(n)
// Space: O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *prev = nullptr;
        TreeNode *cur = root;
        while (cur) {
            if (!cur->left) {
                res.emplace_back(cur->val);
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode *node = cur->left;
                while (node->right && node->right != cur) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = cur;
                    cur = cur->left;
                } else {
                    res.emplace_back(cur->val);
                    prev = cur;
                    node->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
