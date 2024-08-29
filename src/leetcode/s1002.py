from collections import Counter
from typing import List, Optional

from src.model import ListNode


class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        first = Counter(words[0])
        for i in range(1, len(words)):
            another = Counter(words[i])
            missing = list[str]()
            for char, cnt in first.items():
                if char not in another:
                    missing.append(char)
                    continue

                first[char] = min(cnt, another[char])
            for char in missing:
                del first[char]

        result = list[str]()
        for char, cnt in first.items():
            result.extend([char] * cnt)

        return result
