from typing import List


class Solution:

    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        candies = [0] * n
        for i in range(n):
            if i > 0 and ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1
            else:
                candies[i] = 1

        for i in range(n - 1, -1, -1):
            if i < n - 1 and ratings[i] > ratings[i + 1]:
                candies[i] = max(candies[i], candies[i + 1] + 1)
            else:
                candies[i] = max(candies[i], 1)

        return sum(candies)
