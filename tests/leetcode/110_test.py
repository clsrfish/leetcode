import pytest

from src.leetcode.s110 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([3, 9, 20, None, None, 15, 7], True),
    ([1, 2, 2, 3, 3, None, None, 4, 4], False),
    ([], True),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: int):
    root = TreeNode.fromList(nums)
    result = Solution().isBalanced(root)
    assert result == expected
