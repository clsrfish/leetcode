import pytest

from src.leetcode.s108 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([-10, -3, 0, 5, 9], [0, -3, 9, -10, None, 5]),
    ([1, 3], [3, 1]),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums, expected):
    result = Solution().sortedArrayToBST(nums)
    assert TreeNode.toList(result) == expected
