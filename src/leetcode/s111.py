from typing import Optional

from src.model import TreeNode


class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        if root.left is not None and root.right is not None:
            return 1 + min(self.minDepth(root.left), self.minDepth(root.right))
        if root.left is not None:
            return 1 + self.minDepth(root.left)
        if root.right is not None:
            return 1 + self.minDepth(root.right)

        return 1
