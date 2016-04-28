#include "leetcode.h"

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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (root == nullptr || p == nullptr || q == nullptr) return nullptr;

		if ((root == p) || (root == q))
		{
			return root;
		}

		auto left = lowestCommonAncestor(root->left, p, q);
		auto right = lowestCommonAncestor(root->right, p, q);

		if ((left == p && right == q) || (left == q && right == p))
		{
			return root;
		}
		if (left != nullptr) return left;
		if (right != nullptr) return right;

		return nullptr;
    }
};

int main()
{
	vector<TreeNode> nodes{3,5,1,6,2,0,8,7,4};
	auto root = &nodes[0];
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];
	nodes[1].left = &nodes[3];
	nodes[1].right = &nodes[4];
	nodes[2].left = &nodes[5];
	nodes[2].right = &nodes[6];
	nodes[4].left = &nodes[7];
	nodes[4].right = &nodes[8];

	Solution so;
	auto node = so.lowestCommonAncestor(root, &nodes[7], &nodes[8]);
	if (node != nullptr)
		cout << node->val << endl;

	return 0;
}
