from typing import Optional

from src.model import TreeNode


class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None or root.val == val:
            return root
        if root.val > val:
            return self.searchBST(root.left, val)
        return self.searchBST(root.right, val)
