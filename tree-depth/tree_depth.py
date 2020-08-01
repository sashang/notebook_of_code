class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def depth(self, node):
        stack = [(1, node)]
        max_depth = 1
        while len(stack) > 0:
            depth, n = stack.pop()
            if n:
                max_depth = max(depth, max_depth)
                stack.append((depth+1, n.left))
                stack.append((depth+1, n.right))

        return max_depth

    def printNode(self, node):
        if node is None:
            return
        self.printNode(node.left)
        print(f"val={node.val}\n")
        self.printNode(node.right)

n = Node(0)
n.left = Node(1)
n.right = Node(2)
n.right.right = Node(3)
n.right.right.left = Node(3)

print(f"depth = {Solution().depth(n)}")
