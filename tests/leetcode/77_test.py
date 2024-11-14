import pytest

from src.leetcode.s77 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    (4, 2, [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]]),
    (1, 1, [[1]]),
]


@pytest.mark.parametrize("n,k,expected", dataset())
def test(n, k, expected):
    result = Solution().combine(n, k)
    assert result == expected
