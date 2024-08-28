from collections import Counter
from typing import Dict


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        d = {}  # type: Dict[str,int]
        for c in s:
            if c not in d:
                d[c] = 1
            else:
                d[c] += 1

        for c in t:
            if c not in d:
                return False
            else:
                d[c] -= 1

        for count in d.values():
            if count != 0:
                return False
        return True
