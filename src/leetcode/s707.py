from typing import List, Optional

from src.model import ListNode


class MyLinkedList:

    def __init__(self):
        self.head = ListNode(0)

    def get(self, index: int) -> int:
        if index >= self.head.val:
            return -1
        cur = self.head
        for _ in range(0, index + 1):
            cur = cur.next
        return cur.val

    def addAtHead(self, val: int) -> None:
        self.head.next = ListNode(val, self.head.next)
        self.head.val += 1

    def addAtTail(self, val: int) -> None:
        tail = self.head
        while tail.next is not None:
            tail = tail.next
        tail.next = ListNode(val)
        self.head.val += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.head.val:
            return

        pre = self.head
        cur = pre.next
        for _ in range(0, index):
            pre = cur
            cur = pre.next
        pre.next = ListNode(val, cur)

        self.head.val += 1

    def deleteAtIndex(self, index: int) -> None:
        if index >= self.head.val:
            return

        pre = self.head
        cur = pre.next
        for _ in range(0, index):
            pre = cur
            cur = pre.next
        pre.next = cur.next

        self.head.val -= 1
