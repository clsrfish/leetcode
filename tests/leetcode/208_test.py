import pytest

from src.leetcode.s208 import Trie
from src.model import ListNode

dataset = lambda: [
    (
        ["insert", "search", "search", "startsWith", "insert", "search"],
        [["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]],
        [None, True, False, True, None, True],
    ),
]


@pytest.mark.parametrize("funcs,args,expected", dataset())
def test(funcs: list[str], args: list[list[str]], expected: list):
    trie = Trie()
    for i in range(len(funcs)):
        result = getattr(trie, funcs[i])(args[i][0])
        assert (
            expected[i] == result
        ), f'{expected[i]} == trie.{funcs[i]}("{args[i][0]}")'
