#include <iostream>
#include <limits>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
	int tree_height(TreeNode *root)
	{
		if (root == nullptr) return 0;
		return max(tree_height(root->left), tree_height(root->right)) + 1;
	}

    bool isBalanced(TreeNode* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		if (abs(tree_height(root->left) - tree_height(root->right)) > 1)
		{
			return false;
		}
		else
		{
			return isBalanced(root->left) && isBalanced(root->right);
		}
    }
};

int main()
{
	auto root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);

	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(3);

	root->left->left->left = new TreeNode(4);
	root->left->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(4);
	root->left->right->right = new TreeNode(4);
	root->right->left->left = new TreeNode(4);
	root->right->left->right = new TreeNode(4);

	root->left->left->left->left = new TreeNode(5);
	root->left->left->left->right = new TreeNode(5);

	Solution so;
	cout << so.isBalanced(root) << endl;

	return 0;
}
