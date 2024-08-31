class Solution:
    def isHappy(self, n: int) -> bool:
        interediates = set[int]()
        while True:
            interediates.add(n)
            tmp = 0
            while n > 0:
                tmp += (n % 10) ** 2
                n //= 10
            if tmp == 1:
                return True
            if tmp in interediates:
                break

            n = tmp
        return False
