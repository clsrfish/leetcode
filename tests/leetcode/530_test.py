import pytest

from src.leetcode.s530 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([4, 2, 6, 1, 3], 1),
    ([1, 0, 48, None, None, 12, 49], 1),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: int):
    root = TreeNode.fromList(nums)
    result = Solution().getMinimumDifference(root)
    assert result == expected
