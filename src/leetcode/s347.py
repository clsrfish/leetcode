import heapq
from collections import Counter
from typing import List, Tuple


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnts = Counter[int]([x for x in nums])
        q = [(-cnt, num) for num, cnt in cnts.items()]
        heapq.heapify(q)
        result = [heapq.heappop(q)[1] for _ in range(0, k)]
        return result
