from typing import Any

import pytest

from src.leetcode.s232 import MyQueue
from src.model import ListNode

dataset = lambda: [
    (
        ["MyQueue", "push", "push", "peek", "pop", "empty"],
        [[], [1], [2], [], [], []],
        [None, None, None, 1, 1, False],
    ),
    (
        ["MyQueue", "push", "push", "pop", "push", "push", "pop", "peek"],
        [[], [1], [2], [], [3], [4], [], []],
        [None, None, None, 1, None, None, 2, 3],
    ),
]


@pytest.mark.parametrize("funcs,args,expected", dataset())
def test(funcs: list[str], args: list[list[int]], expected: list[Any]):
    myQueue = None  # type: MyQueue
    for i in range(0, len(funcs)):
        invocation = f"{funcs[i]}({','.join(map(lambda x:str(x), args[i]))})"
        if i == 0:
            myQueue = eval(f"{invocation}")
        else:
            result = eval(f"myQueue.{invocation}", {}, {"myQueue": myQueue})
            assert result == expected[i]
