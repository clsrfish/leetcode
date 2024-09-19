import pytest

from src.leetcode.s106 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([9, 3, 15, 20, 7], [9, 15, 7, 20, 3], [3, 9, 20, None, None, 15, 7]),
    ([-1], [-1], [-1]),
]


@pytest.mark.parametrize("inorder,postorder,expected", dataset())
def test(inorder: list[int], postorder: list[int], expected: list[int]):
    root = Solution().buildTree(inorder, postorder)
    assert TreeNode.toList(root) == expected
