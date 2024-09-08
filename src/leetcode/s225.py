class MyStack:

    def __init__(self):
        self.curr = list[int]()
        self.tmp = list[int]()

    def _exchange(self):
        self.curr, self.tmp = self.tmp, self.curr

    def push(self, x: int) -> None:
        self.curr.append(x)

    def pop(self) -> int:
        while len(self.curr) > 1:
            val = self.curr.pop(0)
            self.tmp.append(val)
        val = self.curr.pop()
        self._exchange()
        return val

    def top(self) -> int:
        while len(self.curr) > 0:
            val = self.curr.pop(0)
            self.tmp.append(val)
        self._exchange()
        return val

    def empty(self) -> bool:
        return len(self.curr) == 0
