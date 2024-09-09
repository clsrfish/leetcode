class Solution:
    def removeDuplicates(self, s: str) -> str:

        out = list()
        for char in s:
            if len(out) == 0 or out[-1] != char:
                out.append(char)
            else:
                out.pop()

        return "".join(out)
