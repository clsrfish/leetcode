import pytest

from src.leetcode.s349 import Solution
from src.model import ListNode

dataset = lambda: [
    ([1, 2, 2, 1], [2, 2], [2]),
    ([4, 9, 5], [9, 4, 9, 8, 4], [9, 4]),
]


@pytest.mark.parametrize("nums1,nums2,expected", dataset())
def test(nums1: list[int], nums2: list[int], expected: list[int]):
    result = Solution().intersection(nums1, nums2)
    assert sorted(result) == sorted(expected)
