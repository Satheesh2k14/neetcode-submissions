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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //find path to each node, store answer in aray
        // prune till size is same
        // compare till equal
        vector<TreeNode*> pPath, qPath;
        findPath(root, p -> val, pPath);
        findPath(root, q -> val, qPath);

        int ansIndex = min(pPath.size(), qPath.size()) - 1;
        while (ansIndex > 0) {
            if (pPath[ansIndex] -> val == qPath[ansIndex] -> val) {
                return pPath[ansIndex];
            }
            ansIndex -= 1;
        }

        return root;
    }

    void findPath(TreeNode* curr, int val, vector<TreeNode*> &pathVector) {
        pathVector.push_back(curr);
        if (curr -> val == val) return;
        else if (curr -> val > val) findPath(curr -> left, val, pathVector);
        else findPath(curr -> right, val, pathVector);
    }
};
