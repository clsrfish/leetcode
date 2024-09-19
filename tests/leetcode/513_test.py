import pytest

from src.leetcode.s513 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([2, 1, 3], 1),
    ([1, 2, 3, 4, None, 5, 6, None, None, 7], 7),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: int):
    root = TreeNode.fromList(nums)
    result = Solution().findBottomLeftValue(root)
    assert result == expected
