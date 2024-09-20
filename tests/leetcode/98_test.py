import pytest

from src.leetcode.s98 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([2, 1, 3], True),
    ([5, 1, 4, None, None, 3, 6], False),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: bool):
    root = TreeNode.fromList(nums)
    result = Solution().isValidBST(root)
    assert result == expected
