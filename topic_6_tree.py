class TreeNode:
    def __init__(self, data):
        self.data = data
        self.children = []

    def add_child(self, node):
        self.children.append(node)

    def display(self, level=0):
        print(" " * level * 4 + str(self.data))
        for child in self.children:
            child.display(level + 1)

# Example Usage
root = TreeNode("Hospital")
dept1 = TreeNode("Department 1")
dept2 = TreeNode("Department 2")
root.add_child(dept1)
root.add_child(dept2)
dept1.add_child(TreeNode("Doctor A"))
dept2.add_child(TreeNode("Doctor B"))
print("Tree Structure:")
root.display()
