from typing import List, Optional

from src.model import TreeNode


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if len(inorder) == 0:
            return None
        root_val = postorder[-1]
        root_val_idx = inorder.index(root_val)
        root = TreeNode(root_val)
        root.left = self.buildTree(inorder[0:root_val_idx], postorder[0:root_val_idx])
        root.right = self.buildTree(
            inorder[root_val_idx + 1 :], postorder[root_val_idx:-1]
        )

        return root
