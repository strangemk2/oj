#include <iostream>

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
	bool hasPathSum(TreeNode* root, int sum)
	{
		if (root == nullptr)
			return false;
		if (root->left == nullptr && root->right == nullptr)
		{
			if (sum == root->val)
				return true;
			else
				return false;
		}

		if (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val))
		{
			return true;
		}

		return false;
	}
};

int main()
{
	auto root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	Solution so;
	cout << so.hasPathSum(root, 8) << endl;

	return 0;
}
