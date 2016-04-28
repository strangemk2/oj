import sys

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        def walk_binary_tree(root, route, result):
            if root == None:
                return

            route.append(root)
            if root.left == None and root.right == None:
                result.append('->'.join(map(lambda x: str(x.val), route)))
                route.pop()
                return
            if root.left != None:
                walk_binary_tree(root.left, route, result)
            if root.right != None:
                walk_binary_tree(root.right, route, result)
            route.pop()

        route = []
        result = []
        walk_binary_tree(root, route, result)
        return result


#        nodes = [root]
#        route = []
#        result = []
#        while len(nodes) != 0:
#            node = nodes.pop()
#            if node.right != None:
#                nodes.append(node.right)
#            if node.left != None:
#                nodes.append(node.left)
#
#            route.append(str(node))
#
#            if node.left == None and node.right == None:
#                result.append('->'.join(map(lambda x: str(x), route)))
#                route.pop()
#
#        return result

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.right = TreeNode(5)

solution = Solution()
print solution.binaryTreePaths(root)
