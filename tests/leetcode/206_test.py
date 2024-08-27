import pytest

from src.leetcode.s206 import Solution, SolutionByIteration
from src.model import ListNode

dataset = lambda: [
    ([], []),
    ([1, 2], [2, 1]),
    ([1, 2, 3, 4, 5], [5, 4, 3, 2, 1]),
]


@pytest.mark.parametrize("head,expected", dataset())
def test_recursion(head, expected):
    result = Solution().reverseList(ListNode.fromList(head))
    assert ListNode.toList(result) == expected


@pytest.mark.parametrize("head,expected", dataset())
def test_iteration(head, expected):
    result = SolutionByIteration().reverseList(ListNode.fromList(head))
    assert ListNode.toList(result) == expected
