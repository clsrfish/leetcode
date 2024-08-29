from typing import List


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set(nums1)
        s2 = set(nums2)
        result = set()
        for e in s1:
            if e in s2:
                result.add(e)

        return list(result)
