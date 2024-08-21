import logging

import pytest

from src.leetcode.s147 import Solution
from src.model import ListNode

testdata = [
    ([4, 2, 1, 3], [1, 2, 3, 4]),
    ([-1, 5, 3, 4, 0], [-1, 0, 3, 4, 5]),
]


@pytest.mark.parametrize("input,expected", testdata)
def test(input: list[int], expected: list[int]):
    result = Solution().insertionSortList(ListNode.fromList(input))

    assert expected == ListNode.toList(result)
