from typing import Dict


class Trie:

    def __init__(self):
        self.isWord = False
        self.children = {}  # type: Dict[str,Trie]

    def insert(self, word: str) -> None:
        t = self
        for c in word:
            if c not in t.children:
                t.children[c] = Trie()
            t = t.children[c]
        t.isWord = True

    def search(self, word: str) -> bool:
        t = self
        for c in word:
            if c not in t.children:
                return False
            t = t.children[c]

        return t.isWord

    def startsWith(self, prefix: str) -> bool:
        t = self
        for c in prefix:
            if c not in t.children:
                return False
            t = t.children[c]

        return True
