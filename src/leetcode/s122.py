from typing import List


class Solution:

    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        buyin_price = prices[0]
        for i in range(1, len(prices)):
            if prices[i] <= buyin_price:
                buyin_price = prices[i]
            else:
                profit += prices[i] - buyin_price
                buyin_price = prices[i]

        return profit
