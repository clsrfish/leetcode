import pytest

from src.leetcode.s122 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    ([7, 1, 5, 3, 6, 4], 7),
    ([1, 2, 3, 4, 5], 4),
    ([7, 6, 4, 3, 1], 0),
]


@pytest.mark.parametrize("prices,expected", dataset())
def test(prices, expected):
    result = Solution().maxProfit(prices)
    assert result == expected
