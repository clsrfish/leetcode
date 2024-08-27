import pytest

from src.leetcode.s707 import MyLinkedList
from src.model import ListNode


def test():
    myLinkedList = MyLinkedList()
    myLinkedList.addAtHead(1)
    myLinkedList.addAtTail(3)
    myLinkedList.addAtIndex(1, 2)
    val = myLinkedList.get(1)
    assert val == 2
    myLinkedList.deleteAtIndex(1)
    val = myLinkedList.get(1)
    assert val == 3
