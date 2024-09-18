import pytest

from src.leetcode.s222 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, 2, 3, 4, 5, 6], 6),
    ([], 0),
    ([1], 1),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: int):
    root = TreeNode.fromList(nums)
    result = Solution().countNodes(root)
    assert result == expected
