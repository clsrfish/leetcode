from typing import List, Optional

from src.model import ListNode


class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if head is None:
            return None
        head = ListNode(-1, head)
        predecessor = head
        cur = predecessor.next
        while cur is not None:
            if cur.val != val:
                predecessor = cur
            else:
                predecessor.next = cur.next
            cur = predecessor.next

        return head.next
