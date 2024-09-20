import pytest

from src.leetcode.s700 import Solution
from src.model import TreeNode

dataset = lambda: [
    ([4, 2, 7, 1, 3], 2, [2, 1, 3]),
    ([4, 2, 7, 1, 3], 5, []),
]


@pytest.mark.parametrize("nums,val,expected", dataset())
def test(nums: list[int], val: int, expected: list[int]):
    root = TreeNode.fromList(nums)
    result = Solution().searchBST(root, val)
    assert TreeNode.toList(result) == expected
