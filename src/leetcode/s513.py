from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def __init__(self) -> None:
        self.max_level = 0
        self.bottom_left_val = None

    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        self.findBottomLeftNode(root, 1)
        return self.bottom_left_val

    def findBottomLeftNode(self, node: Optional[TreeNode], curr_level: int):
        if node is None:
            return
        curr_level += 1
        if node.left is None and node.right is None:
            if curr_level > self.max_level:
                self.max_level = curr_level
                self.bottom_left_val = node.val
        else:
            self.findBottomLeftNode(node.left, curr_level)
            self.findBottomLeftNode(node.right, curr_level)
