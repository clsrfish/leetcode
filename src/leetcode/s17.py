from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    letters = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    }

    def __init__(self) -> None:
        self.result = list[str]()

    def letterCombinations(self, digits: str) -> List[str]:
        self.letterCombinationsBacktrace(0, digits, list[str]())
        return self.result

    def letterCombinationsBacktrace(self, i: int, digits: str, arr: list[str]):
        if i >= len(digits):
            if len(arr) > 0:
                self.result.append("".join(arr))
            return

        for c in Solution.letters[digits[i]]:
            arr.append(c)
            self.letterCombinationsBacktrace(i + 1, digits, arr)
            arr.pop()
