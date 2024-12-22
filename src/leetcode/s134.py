from typing import List


class Solution:

    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        acc, curAcc = 0, 0
        start_pos = 0
        for i in range(len(gas)):
            curAcc += gas[i] - cost[i]
            acc += gas[i] - cost[i]
            if curAcc < 0:
                start_pos = i + 1
                curAcc = 0

        return start_pos if acc >= 0 else -1
