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
	void minDept_impl(TreeNode *root, int &result)
	{
		static int depth = 0;

		if (root == nullptr)
		{
			return;
		}

		depth++;
		if (root->left == nullptr && root->right == nullptr)
		{
			if (result == 0 || depth < result)
			{
				result = depth;
			}
			depth--;
			return;
		}

		minDept_impl(root->left, result);
		minDept_impl(root->right, result);

		depth--;
	}

    int minDepth(TreeNode* root)
	{
		int result = 0;
		minDept_impl(root, result);
		return result;
    }
};

int main()
{
	auto root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	Solution so;
	cout << so.minDepth(root) << endl;

	return 0;
}
