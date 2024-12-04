from typing import List


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g = sorted(g)
        s = sorted(s)
        i = 0
        for sj in s:
            if i >= len(g):
                break
            if sj >= g[i]:
                i += 1

        return i
