from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[None] * n for _ in range(0, n)]  # type: list[list[int]]
        x = 0
        y = 0
        i = 0
        while i < n**2:
            # right
            while i < n**2:
                i += 1
                matrix[y][x] = i
                if x < n - 1 and matrix[y][x + 1] is None:
                    x += 1
                else:
                    y += 1
                    break

            # down
            while i < n**2:
                i += 1
                matrix[y][x] = i
                if y < n - 1 and matrix[y + 1][x] is None:
                    y += 1
                else:
                    x -= 1
                    break
            # left
            while i < n**2:
                i += 1
                matrix[y][x] = i
                if x > 0 and matrix[y][x - 1] is None:
                    x -= 1
                else:
                    y -= 1
                    break

            # up
            while i < n**2:
                i += 1
                matrix[y][x] = i
                if y > 0 and matrix[y - 1][x] is None:
                    y -= 1
                else:
                    x += 1
                    break
        return matrix
