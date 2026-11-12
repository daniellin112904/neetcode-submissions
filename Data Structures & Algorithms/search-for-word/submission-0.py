"""
Input: 2d array
Output: bool: if we can find word
Method: brute force dfs to see if we can find every word
Plan:
-get row and col
-set for letters in word we already found
-helper dfs function with row, col, and i (keep track of how many chars we found):
    -if i = len: we found word => return True
    -if out of bound, wrong word, or dup word => return False in dfs
"""

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])
        found = set()

        def dfs(r, c, i):
            if i == len(word):
                return True

            if r < 0 or c < 0 or r >= rows or c >= cols or word[i] != board[r][c] or (r, c) in found:
                return False

            found.add((r, c))
            result = (dfs(r+1, c, i+1) or dfs(r, c+1, i+1) or dfs(r-1, c, i+1) or dfs(r, c-1, i+1))

            found.remove((r, c))
            return result

        for r in range(rows):
            for c in range(cols):
                if dfs(r, c, 0):
                    return True

        return False