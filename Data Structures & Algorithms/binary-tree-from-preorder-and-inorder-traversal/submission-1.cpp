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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        TreeNode* answer;
        int lastIndex = preorder.size() - 1;
        //build hash for inorder
        unordered_map<int, int> inorderIndexMap;

        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        } 
        //parse tree
        answer = parseOrder(preorder, 0, lastIndex, inorder, 0, lastIndex, inorderIndexMap);
        return answer;
    }

    TreeNode* parseOrder(vector<int>& preorder, int preS, int preE, vector<int>& inorder, int inS, int inE, unordered_map<int, int>& inorderIndexMap) {
        if (preS > preE || inS > inE) return nullptr;
        TreeNode* root = new TreeNode(preorder[preS]);

        int rootIndexInOrder = inorderIndexMap[preorder[preS]];
        int noOfLeftTreeNodes = rootIndexInOrder - inS;
        //parse left tree only if more elements exist
        root -> left = parseOrder(preorder, preS + 1, preS + noOfLeftTreeNodes, inorder, inS, rootIndexInOrder - 1, inorderIndexMap);

        //parse right tree
        root -> right = parseOrder(preorder, preS + noOfLeftTreeNodes + 1, preE, inorder, rootIndexInOrder + 1, inE, inorderIndexMap);

        return root;

    }
};

/*
Pre first is N, then L R. So we know starting N pre[0]
then whatever exists before pre[0] in inO is Left sub-tree
after pre[0] in order is right sub-tree

simple example

1 2 3
2 1 3

first is 1
left sub-tree 2
right sub-tree 3. so done

now, 

pre - 1 2 3 4
inO - 2 1 3 4

left subtree is simple
right sub-tree is 3, 4

first element after pre[0] in inorder is right subtree start.
so here 3

go back to pre-order 3 4. so 4 can be left or right.
any eleemnt after 1 before 3 in inorder.. nope so 4 is right subtree 
*/
