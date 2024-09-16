from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self._isSymmetric(root.left, root.right)

    def _isSymmetric(self, left: Optional[TreeNode], right: Optional[TreeNode]) -> bool:
        if left is None and right is None:
            return True
        if left is not None and right is not None:
            if left.val != right.val:
                return False
            return self._isSymmetric(left.left, right.right) and self._isSymmetric(
                left.right, right.left
            )

        return False
