from typing import List, Optional

from src.model import ListNode, TreeNode


class Solution:

    def candy(self, ratings: List[int]) -> int:
        i = 0
        candies = [0] * len(ratings)
        while i < len(ratings):
            while (i + 1) < len(ratings) and ratings[i] >= ratings[i + 1]:
                i += 1

            candies[i] = 1
            for back in range(1, i + 1):
                j = i - back
                if ratings[j] < ratings[j + 1]:
                    break
                elif ratings[j] > ratings[j + 1]:
                    candies[j] = max(candies[j + 1] + 1, candies[j])
                else:
                    if candies[j] == 0:
                        candies[j] = 1
            if i == len(ratings) - 1:
                break

            for j in range(i + 1, len(ratings)):
                if ratings[j] < ratings[j - 1]:
                    i = j
                    break
                elif ratings[j] > ratings[j - 1]:
                    candies[j] = candies[j - 1] + 1
                else:
                    candies[j] = 1
                i = j + 1

        return sum(candies)
