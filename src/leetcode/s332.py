import logging
from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:
    def __init__(self) -> None:
        self.itinerary = None  # type: list[list[str]]
        self.used = list[bool]()

    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        self.used = [False for _ in tickets]
        self._findItineraryBacktrace(tickets, list[list[str]]())
        result = list[str]()
        result.append(self.itinerary[0][0])
        result.append(self.itinerary[0][1])
        for i in range(1, len(self.itinerary)):
            result.append(self.itinerary[i][1])
        return result

    def _findItineraryBacktrace(self, tickets: list[list[str]], legs: list[list[str]]):
        if len(legs) == len(tickets):
            if not self.itinerary:
                self.itinerary = legs[:]
            elif self.itinerary > legs:
                self.itinerary = legs[:]
            return

        for i in range(0, len(tickets)):
            ticket = tickets[i]
            if self.used[i]:
                continue

            if len(legs) == 0 and ticket[0] != "JFK":
                continue

            if len(legs) == 0 and self.itinerary and self.itinerary[0] < ticket:
                continue

            if len(legs) > 0 and ticket[0] != legs[-1][1]:
                continue

            legs.append(ticket)
            self.used[i] = True
            self._findItineraryBacktrace(tickets, legs)
            self.used[i] = False
            legs.pop()
