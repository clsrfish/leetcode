from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    @staticmethod
    def fromList(source: list[int]) -> "TreeNode":
        source = list(source)
        if len(source) == 0:
            return None
        i = 0
        root = TreeNode(source[i])
        i += 1
        queue = list[TreeNode]()
        queue.append(root)
        while len(queue) > 0 and i < len(source):
            node = queue.pop(0)
            left_val = source[i]
            i += 1
            if left_val is not None:
                node.left = TreeNode(left_val)
                queue.append(node.left)
            if i >= len(source):
                break

            right_val = source[i]
            i += 1
            if right_val is not None:
                node.right = TreeNode(right_val)
                queue.append(node.right)

        return root

    @staticmethod
    def toList(root: "TreeNode") -> list[int]:
        result = list[int]()
        queue = list[TreeNode]()
        if root is not None:
            queue.append(root)
        while len(queue) > 0:
            node = queue.pop(0)
            result.append(node.val if node else None)
            if node is None:
                continue
            queue.append(node.left)
            queue.append(node.right)
        while len(result) > 0 and result[-1] is None:
            result.pop()
        return result

    def findNode(root: Optional["TreeNode"], val: int) -> Optional["TreeNode"]:
        if root is None:
            return None
        if root.val == val:
            return root
        return TreeNode.findNode(root.left, val) or TreeNode.findNode(root.right, val)
