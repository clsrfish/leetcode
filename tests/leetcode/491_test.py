import pytest

from src.leetcode.s491 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    (
        [4, 6, 7, 7],
        [[4, 6], [4, 6, 7], [4, 6, 7, 7], [4, 7], [4, 7, 7], [6, 7], [6, 7, 7], [7, 7]],
    ),
    ([4, 4, 3, 2, 1], [[4, 4]]),
]


@pytest.mark.skip()
@pytest.mark.parametrize("nums,expected", dataset())
def test(nums, expected):
    result = Solution().findSubsequences(nums)
    assert sorted(result) == sorted(expected)
