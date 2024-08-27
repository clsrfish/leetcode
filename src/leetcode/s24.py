from typing import List, Optional

from src.model import ListNode


class Solution:

    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None  # type: ListNode
        curr = head
        while curr is not None:
            next = curr.next
            if next is None:
                break

            nextNext = next.next

            if prev is not None:
                prev.next = next
            else:
                head = next
            next.next = curr
            curr.next = nextNext

            prev = curr
            curr = nextNext
        return head
