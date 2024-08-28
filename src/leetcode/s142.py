from typing import List, Optional

from src.model import ListNode


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

            if fast == slow:
                fast = head
                break

        if fast is None or fast.next is None:
            return None

        while fast != slow:
            fast = fast.next
            slow = slow.next

        return slow
