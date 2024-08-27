from typing import List, Optional

from src.model import ListNode


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        newHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return newHead


class SolutionByIteration:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, head
        while curr is not None:
            next, curr.next = curr.next, prev
            prev, curr = curr, next

        return prev
