from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.inOrderTraverse(root, 0)
        return root

    def inOrderTraverse(self, root: Optional[TreeNode], sum: int) -> int:
        if root is None:
            return sum
        leftSum = self.inOrderTraverse(root.right, sum)
        root.val = root.val + leftSum
        return self.inOrderTraverse(root.left, root.val)
