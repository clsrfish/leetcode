import pytest

from src.leetcode.s454 import Solution, Solution2
from src.model import ListNode

dataset = lambda: [
    ([1, 2], [-2, -1], [-1, 2], [0, 2], 2),
    ([0], [0], [0], [0], 1),
    ([-1, -1], [-1, 1], [-1, 1], [1, -1], 6),
]


@pytest.mark.parametrize("nums1,nums2,nums3,nums4,expected", dataset())
def test(nums1, nums2, nums3, nums4, expected):
    result = Solution().fourSumCount(nums1, nums2, nums3, nums4)
    assert result == expected


@pytest.mark.parametrize("nums1,nums2,nums3,nums4,expected", dataset())
def test2(nums1, nums2, nums3, nums4, expected):
    result = Solution2().fourSumCount(nums1, nums2, nums3, nums4)
    assert result == expected
