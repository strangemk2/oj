#include <iostream>
#include <vector>
#include <stack>

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
	void levelOrderBottom_impl(TreeNode *root, vector<vector<int>> &result)
	{
		static int depth = 0;

		if (root == nullptr)
		{
			return;
		}

		depth++;
		levelOrderBottom_impl(root->left, result);
		levelOrderBottom_impl(root->right, result);
		result.push_back(vector<int>);
		depth--;

		result.back().push_back(root->val);
	}

    vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> ret;
		levelOrderBottom_impl(root, ret);

		reverse(ret.begin(), ret.end());
		return ret;
    }
};
