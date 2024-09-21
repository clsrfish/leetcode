from src.model import TreeNode


class Solution:
    def lowestCommonAncestor(
        self, root: TreeNode, p: TreeNode, q: TreeNode
    ) -> TreeNode:
        path2p = list[TreeNode]()
        self.findPath(root, p, path2p)
        path2q = list[TreeNode]()
        self.findPath(root, q, path2q)
        ancestor = root
        for i in range(1, min(len(path2p), len(path2q))):
            if path2p[i] == path2q[i]:
                ancestor = path2p[i]
            else:
                break

        return ancestor

    def findPath(self, root: TreeNode, target: TreeNode, path: list[TreeNode]) -> bool:
        if root is None:
            return False
        path.append(root)
        if root == target:
            return True
        elif self.findPath(root.left, target, path):
            return True
        elif self.findPath(root.right, target, path):
            return True
        path.pop()
        return False
