import pytest

from src.leetcode.s101 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, 2, 2, 3, 4, 4, 3], True),
    ([1, 2, 2, None, 3, None, 3], False),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: bool):
    root = TreeNode.fromList(nums)
    result = Solution().isSymmetric(root)
    assert result == expected
