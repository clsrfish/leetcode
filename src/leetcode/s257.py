from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        path = list[str]()
        paths = list[str]()
        self.traverseTree(root, path, paths)
        return paths

    def traverseTree(self, node: Optional[TreeNode], path: list[int], paths: list[str]):
        if node is None:
            return
        path.append(str(node.val))
        if node.left is None and node.right is None:
            paths.append("->".join(path))
        else:
            self.traverseTree(node.left, path, paths)
            self.traverseTree(node.right, path, paths)
        path.pop(-1)
