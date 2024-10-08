from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False

        targetSum -= root.val

        if root.left is None and root.right is None:
            return targetSum == 0
        return self.hasPathSum(root.left, targetSum) or self.hasPathSum(
            root.right, targetSum
        )
