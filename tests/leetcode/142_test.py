import pytest

from src.leetcode.s142 import Solution
from src.model import ListNode

dataset = lambda: [
    ([3, 2, 0, -4], 1),
    ([1, 2], 0),
    ([1], -1),
]


@pytest.mark.parametrize("nums,pos", dataset())
def test(nums: list[int], pos: int):
    head = ListNode.fromList(nums)
    tail = ListNode.findTail(head)
    expected = ListNode.atPos(head, pos)
    tail.next = expected
    result = Solution().detectCycle(head)
    assert result == expected
