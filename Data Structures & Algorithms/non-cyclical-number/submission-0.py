class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()

        sum = n
        while sum != 1:
            temp = 0
            while n != 0:
                digit = n % 10
                n = n//10
                temp += digit*digit
            sum = temp
            n = temp
            if sum in seen:
                return False
            seen.add(sum)

        return True