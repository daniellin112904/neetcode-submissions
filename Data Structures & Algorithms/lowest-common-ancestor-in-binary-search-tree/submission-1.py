"""
Input: root of tree
Output: node of LCA
method: dfs to see if we can reach p and q from a given node
Edgecases:
-no root => return None
Plan:
-base: if root = p or q: return root
-recursively call function on left and right
-if they both exist: return root
-else: return whatever exist (None if both doesn't)
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root:
            return None

        if root.val == p.val or root.val == q.val:
            return root

        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        if left and right:
            return root
        else:
            return left or right