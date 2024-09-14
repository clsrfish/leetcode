import collections
from typing import List


class Solution:
    def findMaxValPosition(self, nums: List[int], start: int, end: int) -> int:

        maxVal = nums[start]
        maxValPos = start
        for i in range(start + 1, end + 1):
            if nums[i] >= maxVal:
                maxVal = nums[i]
                maxValPos = i
        return maxValPos

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = list[int]()
        left, right = 0, k - 1
        maxValPosition = -1
        while right < len(nums):
            if maxValPosition < left:
                maxValPosition = self.findMaxValPosition(nums, left, right)
            elif nums[right] >= nums[maxValPosition]:
                maxValPosition = right
            result.append(nums[maxValPosition])

            left += 1
            right += 1

        return result


class SolutionON:

    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = list[int]()
        maxValPos = collections.deque(maxlen=k)
        for i in range(0, k):
            while len(maxValPos) > 0 and nums[i] >= nums[maxValPos[-1]]:
                maxValPos.pop()
            maxValPos.append(i)

        result.append(nums[maxValPos[0]])
        for i in range(k, len(nums)):
            while len(maxValPos) > 0 and nums[i] >= nums[maxValPos[-1]]:
                maxValPos.pop()
            maxValPos.append(i)

            while len(maxValPos) > 0 and maxValPos[0] <= i - k:
                maxValPos.popleft()

            result.append(nums[maxValPos[0]])
        return result
