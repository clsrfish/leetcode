import pytest

from src.leetcode.s104 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([3, 9, 20, None, None, 15, 7], 3),
    ([1, None, 2], 2),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: int):
    root = TreeNode.fromList(nums)
    result = Solution().maxDepth(root)
    assert result == expected
