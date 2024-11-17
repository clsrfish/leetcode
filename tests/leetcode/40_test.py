import pytest

from src.leetcode.s40 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([10, 1, 2, 7, 6, 1, 5], 8, [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]),
    ([2, 5, 2, 1, 2], 5, [[1, 2, 2], [5]]),
]


@pytest.mark.parametrize("candidates,target,expected", dataset())
def test(candidates, target, expected):
    result = Solution().combinationSum2(candidates, target)
    assert sorted(result) == expected
