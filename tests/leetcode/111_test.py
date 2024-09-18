import pytest

from src.leetcode.s111 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([3, 9, 20, None, None, 15, 7], 2),
    ([2, None, 3, None, 4, None, 5, None, 6], 5),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: int):
    root = TreeNode.fromList(nums)
    result = Solution().minDepth(root)
    assert result == expected
