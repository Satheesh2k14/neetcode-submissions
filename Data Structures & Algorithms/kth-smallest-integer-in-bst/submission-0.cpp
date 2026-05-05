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
    int kthSmallest(TreeNode* root, int k) {
        // L root R traversal
        // stack. top 
        stack<int> kValues;
        traverse(root, kValues, k);

        return kValues.top();
    }

    void traverse(TreeNode* curr, stack<int>& kValues, int k) {
        if (curr == NULL) return;

        if (curr -> left) {
            traverse(curr -> left, kValues, k);
        }
        if (kValues.size() < k) {
            kValues.push(curr -> val);
        } else {
            return;
        }

        if (curr -> right) {
            traverse(curr -> right, kValues, k);
        }
    }


};
