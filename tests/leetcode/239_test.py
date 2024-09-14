import pytest

from src.leetcode.s239 import Solution

dataset = lambda: [
    ([1, 3, -1, -3, 5, 3, 6, 7], 3, [3, 3, 5, 5, 6, 7]),
    ([1], 1, [1]),
]


@pytest.mark.parametrize("nums,k,expected", dataset())
def test(nums: list[int], k: int, expected: list[int]):
    result = Solution().maxSlidingWindow(nums, k)
    assert result == expected
