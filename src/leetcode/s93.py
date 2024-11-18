from typing import List


class Solution:

    def __init__(self) -> None:
        self.result = list[str]()

    def restoreIpAddresses(self, s: str) -> List[str]:
        self.restpreIpAddressesBacktrace(s, 0, list[str]())
        return self.result

    def restpreIpAddressesBacktrace(self, s: str, pos: int, segments: list[str]):
        if len(segments) == 4:
            if pos == len(s):
                self.result.append(".".join(segments))
            return
        for i in range(pos, min(pos + 3, len(s))):
            if self.isValidSegment(s[pos : i + 1]):
                segments.append(s[pos : i + 1])
                self.restpreIpAddressesBacktrace(s, i + 1, segments)
                segments.pop()
            else:
                break

    def isValidSegment(self, s: str):
        if len(s) == 1:
            return True
        if s.startswith("0"):
            return False
        return int(s) <= 255
