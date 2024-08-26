import pytest

from src.leetcode.s704 import Solution
from src.model import ListNode

dataset = lambda: [
    ([-1, 0, 3, 5, 9, 12], 9, 4),
    ([-1, 0, 3, 5, 9, 12], 2, -1),
]


@pytest.mark.parametrize("nums,target,expected", dataset())
def test(nums: list[int], target: int, expected: int):
    solution = Solution()
    result = solution.search(nums, target)
    assert result == expected
