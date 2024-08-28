# Definition for singly-linked list.
from typing import Optional


class ListNode:

    def __init__(self, val=0, next: Optional["ListNode"] = None):
        self.val = val
        self.next = next

    @staticmethod
    def fromList(source: list[int]) -> "ListNode":
        head = ListNode()
        tail = head
        for e in source:
            tail.next = ListNode(e)
            tail = tail.next

        return head.next

    @staticmethod
    def toList(head: "ListNode") -> list[int]:
        result = list()
        while head is not None:
            result.append(head.val)
            head = head.next

        return result

    def findTail(head: "ListNode") -> "ListNode":
        while head and head.next:
            head = head.next
        return head

    def atPos(head: "ListNode", pos: int) -> "ListNode":
        if pos < 0:
            return None

        for _ in range(0, pos):
            if head == None:
                return None
            head = head.next

        return head
