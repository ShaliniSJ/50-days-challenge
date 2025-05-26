class Node:
    def __init__(self, data, key):
        self.data = data
        self.key = key
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.size = 0
        self.mp = {}
        self.root = Node(-1, -1)  # dummy head
        self.tail = Node(-1, -1)  # dummy tail
        self.root.next = self.tail
        self.tail.prev = self.root

    def _remove(self, node):
        prev = node.prev
        nxt = node.next
        prev.next = nxt
        nxt.prev = prev

    def _add_to_front(self, node):
        node.next = self.root.next
        node.prev = self.root
        self.root.next.prev = node
        self.root.next = node

    def get(self, key: int) -> int:
        if key in self.mp:
            node = self.mp[key]
            self._remove(node)
            self._add_to_front(node)
            return node.data
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.mp:
            node = self.mp[key]
            node.data = value
            self._remove(node)
            self._add_to_front(node)
        else:
            if self.size == self.cap:
                # Remove LRU from the tail
                lru = self.tail.prev
                self._remove(lru)
                del self.mp[lru.key]
                self.size -= 1
            new_node = Node(value, key)
            self._add_to_front(new_node)
            self.mp[key] = new_node
            self.size += 1
