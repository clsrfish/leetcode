import pytest

from src.leetcode.s977 import Solution
from src.model import ListNode

dataset = lambda: [
    ([-4, -1, 0, 3, 10], [0, 1, 9, 16, 100]),
    ([-7, -3, 2, 3, 11], [4, 9, 9, 49, 121]),
]


@pytest.mark.parametrize("nums,expected", dataset())
def test(nums: list[int], expected: list[int]):
    solution = Solution()
    result = solution.sortedSquares(nums)
    assert result == expected
