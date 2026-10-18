class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        res = 0

        for i in range(len(prices)):
            
            price = prices[i]
            min_price = min(min_price, price)
            
            res = max(res, price - min_price)
        
        return res
        