from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def __init__(self) -> None:
        self.curr_val = 0
        self.curr_cnt = 0
        self.max_cnt = 0
        self.result = list[int]()

    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.traverseByInorder(root)
        return self.result

    def updateMode(self, val: int):
        if val == self.curr_val:
            self.curr_cnt += 1
        else:
            self.curr_cnt = 1
            self.curr_val = val

        if self.curr_cnt == self.max_cnt:
            self.result.append(val)
        elif self.curr_cnt > self.max_cnt:
            self.result = [val]
            self.max_cnt = self.curr_cnt

    def traverseByInorder(self, node: Optional[TreeNode]):
        if node is None:
            return
        self.traverseByInorder(node.left)
        self.updateMode(node.val)
        self.traverseByInorder(node.right)
