import pytest

from src.leetcode.s1 import Solution
from src.model import ListNode

dataset = lambda: [
    ([2, 7, 11, 15], 9, [0, 1]),
    ([3, 2, 4], 6, [1, 2]),
    ([3, 3], 6, [0, 1]),
]


@pytest.mark.parametrize("nums,target,expected", dataset())
def test(nums: list[int], target: int, expected: list[int]):
    result = Solution().twoSum(nums, target)
    assert result == expected
