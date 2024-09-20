import pytest

from src.leetcode.s654 import Solution
from src.model import TreeNode

dataset = lambda: [
    ([3, 2, 1, 6, 0, 5], [6, 3, 5, None, 2, 0, None, None, 1]),
    ([3, 2, 1], [3, None, 2, None, 1]),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: list[int]):
    root = Solution().constructMaximumBinaryTree(nums)
    assert TreeNode.toList(root) == expected
