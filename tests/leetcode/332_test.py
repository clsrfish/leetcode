import pytest

from src.leetcode.s332 import Solution
from src.model import ListNode, TreeNode

dataset = lambda: [
    (
        [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]],
        ["JFK", "MUC", "LHR", "SFO", "SJC"],
    ),
    (
        [
            ["JFK", "SFO"],
            ["JFK", "ATL"],
            ["SFO", "ATL"],
            ["ATL", "JFK"],
            ["ATL", "SFO"],
        ],
        ["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"],
    ),
]


@pytest.mark.skip
@pytest.mark.parametrize("tickets,expected", dataset())
def test(tickets, expected):
    result = Solution().findItinerary(tickets)
    assert result == expected
