import pytest

from src.leetcode.s27 import Solution
from src.model import ListNode

dataset = lambda: [
    ([3, 2, 2, 3], 3, [2, 2]),
    ([0, 1, 2, 2, 3, 0, 4, 2], 2, [0, 1, 4, 0, 3]),
    ([], 0, []),
    ([3, 3], 3, []),
]


@pytest.mark.parametrize("nums,val,expectedNums", dataset())
def test(nums: list[int], val: int, expectedNums: list[int]):
    solution = Solution()
    k = solution.removeElement(nums, val)
    assert k == len(expectedNums)

    sorted(nums[:k])
    for i in range(0, k):
        assert nums[i] == expectedNums[i]
