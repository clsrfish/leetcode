import pytest

from src.leetcode.s24 import Solution
from src.model import ListNode

dataset = lambda: [
    ([], []),
    ([1], [1]),
    ([1, 2, 3, 4], [2, 1, 4, 3]),
    ([1, 2, 3, 4, 5], [2, 1, 4, 3, 5]),
]


@pytest.mark.parametrize("head,expected", dataset())
def test(head: list[int], expected: list[int]):
    result = Solution().swapPairs(ListNode.fromList(head))
    assert ListNode.toList(result) == expected
