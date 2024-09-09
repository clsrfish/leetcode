from typing import List, Optional

from src.model import ListNode


class Solution:
    def isValid(self, s: str) -> bool:
        parenthesis_pairs = set(["()", "[]", "{}"])
        right_parenthesises = set([")", "]", "}"])
        stk = list[str]()
        for parenthesis in s:
            if parenthesis in right_parenthesises:
                if len(stk) == 0:
                    return False
                left_parenthesis = stk.pop()
                if f"{left_parenthesis}{parenthesis}" in parenthesis_pairs:
                    continue
                return False
            else:
                stk.append(parenthesis)
        return len(stk) == 0
