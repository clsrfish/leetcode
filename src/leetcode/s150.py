from typing import List, Optional

from src.model import ListNode


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = list[int]()
        for token in tokens:
            if token not in ["+", "-", "*", "/"]:
                stack.append(int(token))
                continue

            right = stack.pop()
            left = stack.pop()
            if token == "+":
                stack.append(left + right)
            elif token == "-":
                stack.append(left - right)
            elif token == "*":
                stack.append(left * right)
            elif token == "/":
                stack.append(int(left / right))

        return stack.pop()
