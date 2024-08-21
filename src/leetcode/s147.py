from typing import Optional

from src.model import ListNode


class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head
        tail = head
        head = ListNode(-5001, head)
        pickup = tail.next
        while pickup is not None:
            # move forward the tail
            if pickup.val >= tail.val:
                tail = pickup
            else:
                # find
                predecessor = head
                while predecessor.next.val <= pickup.val:
                    predecessor = predecessor.next
                # insert
                tail.next = pickup.next
                pickup.next = predecessor.next
                predecessor.next = pickup

            pickup = tail.next

        return head.next
