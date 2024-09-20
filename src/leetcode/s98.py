from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        inorder = list[int]()
        self.traverseByInorder(root, inorder)
        for i in range(1, len(inorder)):
            if inorder[i] <= inorder[i - 1]:
                return False
        return True

    def traverseByInorder(self, node: Optional[TreeNode], inorder: list[int]):
        if node is None:
            return
        self.traverseByInorder(node.left, inorder)
        inorder.append(node.val)
        self.traverseByInorder(node.right, inorder)
