from typing import List, Optional

from src.model import ListNode


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        head = ListNode(-1, head)
        fast = head
        for _ in range(0, n):
            fast = fast.next

        prev = None
        slow = head
        while fast is not None:
            fast = fast.next
            prev = slow
            slow = slow.next

        prev.next = slow.next

        return head.next
