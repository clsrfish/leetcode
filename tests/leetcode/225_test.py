import pytest

from src.leetcode.s225 import MyStack

dataset = lambda: [
    (
        ["MyStack", "push", "push", "top", "pop", "empty"],
        [[], [1], [2], [], [], []],
        [None, None, None, 2, 2, False],
    ),
]


@pytest.mark.parametrize("funcs,args,expected", dataset())
def test(funcs, args, expected):
    myStack = None  # type: MyStack
    for i in range(0, len(funcs)):
        invocation = f"{funcs[i]}({','.join(map(lambda x:str(x), args[i]))})"
        if i == 0:
            myStack = eval(f"{invocation}")
        else:
            result = eval(f"myStack.{invocation}", {}, {"myStack": myStack})
            assert result == expected[i]
