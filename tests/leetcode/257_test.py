import pytest

from src.leetcode.s257 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, 2, 3, None, 5], ["1->2->5", "1->3"]),
    ([1], ["1"]),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: list[str]):
    root = TreeNode.fromList(nums)
    result = Solution().binaryTreePaths(root)
    assert result == expected
