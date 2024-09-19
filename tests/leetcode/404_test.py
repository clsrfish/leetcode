import pytest

from src.leetcode.s404 import Solution
from src.model import TreeNode

dataset = lambda: [
    ([3, 9, 20, None, None, 15, 7], 24),
    ([1], 0),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: int):
    root = TreeNode.fromList(nums)
    result = Solution().sumOfLeftLeaves(root)
    assert result == expected
