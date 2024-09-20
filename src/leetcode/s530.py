from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        inorder = list[int]()
        self.traverseByInorder(root, inorder)
        min_diff = inorder[1] - inorder[0]
        for i in range(2, len(inorder)):
            diff = inorder[i] - inorder[i - 1]
            min_diff = min(diff, min_diff)

        return min_diff

    def traverseByInorder(self, node: Optional[TreeNode], inorder: list[int]):
        if node is None:
            return
        self.traverseByInorder(node.left, inorder)
        inorder.append(node.val)
        self.traverseByInorder(node.right, inorder)
