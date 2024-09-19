from typing import Optional

from src.model import TreeNode


class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        return self.sumOfLeftLeavesRecursively(root, False)

    def sumOfLeftLeavesRecursively(self, node: Optional[TreeNode], left: bool) -> int:
        if node is None:
            return 0

        if node.left is None and node.right is None:
            return node.val if left else 0

        return self.sumOfLeftLeavesRecursively(
            node.left, True
        ) + self.sumOfLeftLeavesRecursively(node.right, False)
