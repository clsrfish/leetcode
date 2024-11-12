from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def lowestCommonAncestor(
        self, root: TreeNode, p: TreeNode, q: TreeNode
    ) -> TreeNode:
        path2p = self.findPath(root, p)
        path2q = self.findPath(root, q)
        ancestor = root
        for i in range(1, min(len(path2p), len(path2q))):
            if path2p[i] == path2q[i]:
                ancestor = path2p[i]
            else:
                break

        return ancestor

    def findPath(self, root: TreeNode, target: TreeNode) -> list[TreeNode]:
        path = list()
        while root.val != target.val:
            path.append(root)
            if root.val > target.val:
                root = root.left
            else:
                root = root.right
        path.append(root)
        return path
