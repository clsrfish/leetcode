import pytest

from src.leetcode.s501 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, None, 2, 2], [2]),
    ([0], [0]),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: list[int]):
    root = TreeNode.fromList(nums)
    result = Solution().findMode(root)
    assert result == expected
