"""
Input: root of tree
Output: node of LCA
method: check when p and q isn't both greater or less than root, then they would split and current would be LCA
Plan:
-current = root
-while current:
    -if p and q both > root:
        -move right
    -elif both < root
        -move left
    -else (split, or one of them = root)
        -return current
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        current = root

        while current:
            if p.val < current.val and q.val < current.val:
                current = current.left
            elif p.val > current.val and q.val > current.val:
                current = current.right
            else:
                return current