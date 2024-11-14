import pytest

from src.leetcode.s538 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    (
        [4, 1, 6, 0, 2, 5, 7, None, None, None, 3, None, None, None, 8],
        [30, 36, 21, 36, 35, 26, 15, None, None, None, 33, None, None, None, 8],
    ),
    ([0, None, 1], [1, None, 1]),
    ([1, 0, 2], [3, 3, 2]),
    ([3, 2, 4, 1], [7, 9, 4, 10]),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums, expected):
    root = TreeNode.fromList(nums)
    result = Solution().convertBST(root)
    assert TreeNode.toList(result) == expected
