import pytest

from src.leetcode.s203 import Solution
from src.model import ListNode

dataset = lambda: [
    ([1, 2, 6, 3, 4, 5, 6], 6, [1, 2, 3, 4, 5]),
    ([7, 7, 7, 7], 7, []),
]


@pytest.mark.parametrize("head,val,expected", dataset())
def test(head: list[int], val: int, expected: list[int]):
    result = Solution().removeElements(ListNode.fromList(head), val)
    assert ListNode.toList(result) == expected
