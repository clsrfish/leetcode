import pytest

from src.leetcode.s450 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([5, 3, 6, 2, 4, None, 7], 3, [5, 4, 6, 2, None, None, 7]),
    ([5, 3, 6, 2, 4, None, 7], 0, [5, 3, 6, 2, 4, None, 7]),
    ([], 0, []),
]


@pytest.mark.parametrize("nums,key,expected", dataset())
def test(nums: list[int], key: int, expected: list[int]):
    root = TreeNode.fromList(nums)
    result = Solution().deleteNode(root, key)
    assert TreeNode.toList(result) == expected
