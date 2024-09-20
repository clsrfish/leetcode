from typing import Optional

from src.model import TreeNode


class Solution:
    def mergeTrees(
        self, root1: Optional[TreeNode], root2: Optional[TreeNode]
    ) -> Optional[TreeNode]:
        if root1 and root2:
            root = TreeNode(root1.val + root2.val)
        else:
            root = root1 if root1 else root2

        if root is not None:
            root.left = self.mergeTrees(
                root1.left if root1 else None, root2.left if root2 else None
            )
            root.right = self.mergeTrees(
                root1.right if root1 else None, root2.right if root2 else None
            )

        return root
