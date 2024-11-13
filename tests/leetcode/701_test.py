import pytest

from src.leetcode.s701 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([4, 2, 7, 1, 3], 5, [4, 2, 7, 1, 3, 5]),
    ([40, 20, 60, 10, 30, 50, 70], 25, [40, 20, 60, 10, 30, 50, 70, None, None, 25]),
    ([4, 2, 7, 1, 3, None, None, None, None, None, None], 5, [4, 2, 7, 1, 3, 5]),
]


@pytest.mark.parametrize("nums,val,expected", dataset())
def test(nums, val, expected):
    root = TreeNode.fromList(nums)
    result = Solution().insertIntoBST(root, val)
    assert TreeNode.toList(result) == expected
