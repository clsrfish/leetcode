from collections import Counter
from typing import List, Optional

from src.model import ListNode


class Solution:
    def fourSumCount(
        self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]
    ) -> int:
        return self.nSum(
            [nums1, nums2, nums3, nums4],
            [dict[int, int](), dict[int, int](), dict[int, int](), dict[int, int]()],
            0,
        )

    def nSum(
        self, numss: list[list[int]], cntss: list[dict[int, int]], target: int
    ) -> int:
        total = 0
        cnts = cntss[0]
        nums = numss[0]
        n = len(numss)
        for i in range(len(nums)):
            num = nums[i]
            remain = target - num
            if remain not in cnts:
                if n == 1:
                    count = 1 if remain == 0 else 0
                else:
                    count = self.nSum(numss[1:], cntss[1:], remain)
                cnts[remain] = count
            else:
                count = cnts[remain]
            total += count
        return total


class Solution2:
    def fourSumCount(
        self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]
    ) -> int:
        result = 0
        cnts = Counter[int]()
        for i in range(0, len(nums1)):
            for j in range(0, len(nums2)):
                cnts[nums1[i] + nums2[j]] += 1
        for k in range(0, len(nums3)):
            for l in range(0, len(nums4)):
                result += cnts[-nums3[k] - nums4[l]]

        return result
