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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both empty trees
        if (!p && !q) return true;
        // 1: only one is empty. 2: both is nonempty, check vals
        if ((!p || !q) || (p->val != q->val)) return false;

        // Recursively call on children
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
