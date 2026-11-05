"""
Input: root of tree
Output: list of lists
Method: bfs
Edgecases: no root => return empty list
Plan:
-list to hold result
-add root to queue
-while queue:
    -get length of current queue (length of that level)
    -list to hold all values in that level
    -for length in current level:
        -pop node, check if its null
        -if not null, add to level list, and append it's children
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []

        queue = deque()
        queue.append(root)

        while queue:
            lLen = len(queue)
            level = []
            for i in range(lLen):
                node = queue.popleft()
                if node:
                    level.append(node.val)
                    queue.append(node.left)
                    queue.append(node.right)
            if level:
                result.append(level)
        return result
        