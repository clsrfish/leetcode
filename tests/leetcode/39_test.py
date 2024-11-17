import pytest

from src.leetcode.s39 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([2, 3, 6, 7], 7, [[2, 2, 3], [7]]),
    ([2, 3, 5], 8, [[2, 2, 2, 2], [2, 3, 3], [3, 5]]),
    ([2], 1, []),
]


@pytest.mark.parametrize("candidates,target,expected", dataset())
def test(candidates, target, expected):
    result = Solution().combinationSum(candidates, target)
    assert result == expected
