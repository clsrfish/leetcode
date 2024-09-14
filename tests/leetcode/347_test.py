import pytest

from src.leetcode.s347 import Solution
from src.model import ListNode

dataset = lambda: [
    ([1, 1, 1, 2, 2, 3], 2, [1, 2]),
    ([1], 1, [1]),
    ([1, 2], 2, [1, 2]),
]


@pytest.mark.parametrize("nums,k,expected", dataset())
def test(nums: list[int], k: int, expected: list[int]):
    result = Solution().topKFrequent(nums, k)
    assert sorted(result) == sorted(expected)
