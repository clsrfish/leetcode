import pytest

from src.leetcode.s189 import Solution, SolutionSlice
from src.model import ListNode

dataset = lambda: [
    ([1, 2, 3, 4, 5, 6], 2, [5, 6, 1, 2, 3, 4]),
    ([1, 2, 3, 4, 5, 6, 7], 3, [5, 6, 7, 1, 2, 3, 4]),
    ([-1, -100, 3, 99], 2, [3, 99, -1, -100]),
    ([1, 2, 3, 4, 5, 6], 4, [3, 4, 5, 6, 1, 2]),
]


@pytest.mark.parametrize("nums,k,expected", dataset())
def test(nums: list[int], k: int, expected: list[int]):
    Solution().rotate(nums, k)
    assert expected == nums


@pytest.mark.parametrize("nums,k,expected", dataset())
def test_slice(nums: list[int], k: int, expected: list[int]):
    SolutionSlice().rotate(nums, k)
    assert expected == nums
