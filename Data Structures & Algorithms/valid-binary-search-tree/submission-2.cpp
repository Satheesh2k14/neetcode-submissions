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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        return checkBST(root, INT_MIN, INT_MAX);
    }

    bool checkBST(TreeNode* root, int left, int right) {
        if (root == NULL) return true;
        if (root -> val <= left) {
            return false;
        } 
        if (root -> val >= right) {
            return false;
        }
        /*if (root -> left) {
            if (root -> val <= root -> left -> val) {
                return false;
            }
        }
        if (root -> right) {
            if (root -> val >= root -> right -> val) {
                return false;
            }
        }*/
        return checkBST(root -> left, left, root -> val) && checkBST(root -> right, root -> val, right); // fix
    
    }
};
