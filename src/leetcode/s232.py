class MyQueue:

    def __init__(self):
        self.head = list[int]()
        self.tail = list[int]()

    def push(self, x: int) -> None:
        self.tail.append(x)

    def pop(self) -> int:
        if len(self.head) == 0:
            while len(self.tail) > 0:
                val = self.tail.pop()
                self.head.append(val)

        return self.head.pop()

    def peek(self) -> int:
        if len(self.head) == 0:
            while len(self.tail) > 0:
                val = self.tail.pop()
                self.head.append(val)

        return self.head[-1]

    def empty(self) -> bool:
        return len(self.head) == 0 and len(self.tail) == 0
