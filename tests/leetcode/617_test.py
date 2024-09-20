import pytest

from src.leetcode.s617 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, 3, 2, 5], [2, 1, 3, None, 4, None, 7], [3, 4, 5, 5, 4, None, 7]),
    ([1], [1, 2], [2, 2]),
]


@pytest.mark.parametrize("nums1,nums2,expected", dataset())
def test(nums1: list[int], nums2: list[int], expected: list[int]):
    root1 = TreeNode.fromList(nums1)
    root2 = TreeNode.fromList(nums2)
    result = Solution().mergeTrees(root1, root2)
    assert TreeNode.toList(result) == expected
