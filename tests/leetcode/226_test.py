import pytest

from src.leetcode.s226 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([4, 2, 7, 1, 3, 6, 9], [4, 7, 2, 9, 6, 3, 1]),
    ([2, 1, 3], [2, 3, 1]),
    ([], []),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: list[int]):
    root = TreeNode.fromList(nums)
    result = Solution().invertTree(root)
    assert TreeNode.toList(result) == expected
