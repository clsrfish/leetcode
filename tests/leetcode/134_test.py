import pytest

from src.leetcode.s134 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([1, 2, 3, 4, 5], [3, 4, 5, 1, 2], 3),
    ([2, 3, 4], [3, 4, 3], -1),
]


@pytest.mark.parametrize("gas,cost,expected", dataset())
def test(gas, cost, expected):
    result = Solution().canCompleteCircuit(gas, cost)
    assert result == expected
