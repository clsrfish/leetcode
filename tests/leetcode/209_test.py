import pytest

from src.leetcode.s209 import Solution
from src.model import ListNode

dataset = lambda: [
    (7, [2, 3, 1, 2, 4, 3], 2),
    (4, [1, 4, 4], 1),
    (11, [1, 1, 1, 1, 1, 1, 1, 1], 0),
]


@pytest.mark.parametrize("target,nums,expected", dataset())
def test(target: int, nums: list[int], expected: int):
    solution = Solution()
    result = solution.minSubArrayLen(target, nums)
    assert result == expected
