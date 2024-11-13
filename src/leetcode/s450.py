from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return root
        if root.val > key:
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        else:
            root = self.mergeTree(root.left, root.right)
        return root

    def mergeTree(self, left: TreeNode, right: TreeNode) -> TreeNode:
        if right is None:
            return left
        node = right
        while node.left is not None:
            node = node.left

        node.left = left
        return right
