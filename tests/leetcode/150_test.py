import pytest

from src.leetcode.s150 import Solution
from src.model import ListNode

testdata = [
    (["2", "1", "+", "3", "*"], 9),
    (["4", "13", "5", "/", "+"], 6),
    (["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"], 22),
]


@pytest.mark.parametrize("input,expected", testdata)
def test(input: list[str], expected: int):
    result = Solution().evalRPN(input)
    assert expected == result
