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
        # if k == 1:
        #     return nums
        result = list[int]()
        maxValPos = list[int]()
        left, right = 0, k - 1
        while right < len(nums):
            if len(maxValPos) > 0 and maxValPos[0] < left:
                maxValPos.pop(0)

            if len(maxValPos) == 0:
                for i in range(left, right + 1):
                    if len(maxValPos) == 0:
                        maxValPos.append(i)
                        continue
                    while len(maxValPos) > 0 and nums[maxValPos[-1]] <= nums[i]:
                        maxValPos.pop()
                    maxValPos.append(i)
            else:
                while len(maxValPos) > 0 and nums[right] >= nums[maxValPos[-1]]:
                    maxValPos.pop()
                maxValPos.append(right)
            result.append(nums[maxValPos[0]])
            left += 1
            right += 1
        return result
