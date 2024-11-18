from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def __init__(self) -> None:
        self.result = list[list[str]]()
        self.palindromeRecords = dict[str, bool]()

    def partition(self, s: str) -> List[List[str]]:
        self.partitionBacktrace(s, 0, list[str]())
        return self.result

    def partitionBacktrace(self, s: str, pos: int, arr: list[str]):
        if len(s) == pos:
            self.result.append(arr[:])
            return

        for i in range(pos, len(s)):
            if self.isPalindrome(s, pos, i):
                arr.append(s[pos : i + 1])
                self.partitionBacktrace(s, i + 1, arr)
                arr.pop()

    def isPalindrome(self, s: str, left: int, right: int) -> bool:
        if left >= right:
            return True
        key = f"{left},{right}"
        if key in self.palindromeRecords:
            return self.palindromeRecords[key]

        match = s[left] == s[right] and self.isPalindrome(s, left + 1, right - 1)
        self.palindromeRecords[key] = match
        return match
