class Stack:
    def __init__(self):
        self.stack = []

    def push(self, data):
        self.stack.append(data)

    def pop(self):
        if self.stack:
            return self.stack.pop()
        return None

    def display(self):
        print("Stack (top -> bottom):", self.stack[::-1])

# Example Usage
stack = Stack()
stack.push("Action 1")
stack.push("Action 2")
stack.push("Action 3")
print("Stack Contents:")
stack.display()
print("Popped Item:", stack.pop())
stack.display()
