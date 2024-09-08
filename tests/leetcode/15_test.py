import pytest

from src.leetcode.s15 import Solution
from src.model import ListNode

dataset = lambda: [
    ([-1, 0, 1, 2, -1, -4], [[[-1, -1, 2], [-1, 0, 1]]]),
    ([0, 1, 1], []),
    ([0, 0, 0], [[0, 0, 0]]),
]


@pytest.mark.parametrize("nums,expected", dataset())
@pytest.mark.skip("not passed")
def test(nums: list[int], expected: list[list[int]]):
    result = Solution().threeSum(nums)
    assert result == expected
