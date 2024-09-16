class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    @staticmethod
    def fromList(source: list[int], i: int = 0) -> "TreeNode":
        if i >= len(source) or source[i] is None:
            return None
        node = TreeNode(source[i])
        node.left = TreeNode.fromList(source, 2 * i + 1)
        node.right = TreeNode.fromList(source, 2 * i + 2)
        return node

    @staticmethod
    def toList(root: "TreeNode") -> list[int]:

        result = list[int]()
        queue = list[TreeNode]()
        if root is not None:
            queue.append(root)
        while len(queue) > 0:
            node = queue.pop(0)
            result.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return result
