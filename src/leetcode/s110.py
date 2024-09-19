from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.isDepthBalanced(root) >= 0

    def isDepthBalanced(self, node: Optional[TreeNode]) -> int:
        if node is None:
            return 0

        left_depth = self.isDepthBalanced(node.left)
        if left_depth < 0:
            return -1
        right_depth = self.isDepthBalanced(node.right)
        if right_depth < 0:
            return -1
        if abs(left_depth - right_depth) > 1:
            return -1
        return 1 + max(left_depth, right_depth)
