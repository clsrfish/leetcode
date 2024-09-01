from collections import Counter
from typing import List, Optional

from src.model import ListNode


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        chars = Counter(magazine)
        for i in range(0, len(ransomNote)):
            char = ransomNote[i]
            chars[char] -= 1
            if chars[char] < 0:
                return False

        return True
