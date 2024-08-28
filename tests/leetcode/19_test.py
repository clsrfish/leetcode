import pytest

from src.leetcode.s19 import Solution
from src.model import ListNode

dataset = lambda: [
    ([1, 2, 3, 4, 5], 2, [1, 2, 3, 5]),
    ([1], 1, []),
    ([1, 2], 1, [1]),
]


@pytest.mark.parametrize("head,n,expected", dataset())
def test(head, n, expected):
    result = Solution().removeNthFromEnd(ListNode.fromList(head), n)
    assert ListNode.toList(result) == expected
