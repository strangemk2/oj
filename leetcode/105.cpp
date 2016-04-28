#include <iostream>
#include <vector>

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

size_t find_index(const vector<int> &v, int value)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void print_preorder(TreeNode *root)
{
	if (root)
	{
		cout << root->val << ", ";
		print_preorder(root->left);
		print_preorder(root->right);
	}
}

void print_inorder(TreeNode *root)
{
	if (root)
	{
		print_inorder(root->left);
		cout << root->val << ", ";
		print_inorder(root->right);
	}
}

void rm_tree(TreeNode *root)
{
	if (root)
	{
		rm_tree(root->left);
		rm_tree(root->right);

		delete root;
	}
}

class Solution
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (preorder.size() == 0)
		{
			return nullptr;
		}
		if (preorder.size() == 1)
		{
			return new TreeNode(preorder[0]);
		}

		auto root_value = preorder[0];
		auto inorder_root_index = find_index(inorder, root_value);

		auto root = new TreeNode(preorder[0]);

		vector<int> left_inorder, right_inorder;
		left_inorder.assign(inorder.begin(), inorder.begin() + inorder_root_index);
		right_inorder.assign(inorder.begin() + inorder_root_index + 1, inorder.end());
		vector<int> left_preorder, right_preorder;
		left_preorder.assign(preorder.begin() + 1, preorder.begin() + 1 + inorder_root_index);
		right_preorder.assign(preorder.begin() + 1 + inorder_root_index, preorder.end());

		root->left = buildTree(left_preorder, left_inorder);
		root->right = buildTree(right_preorder, right_inorder);

		return root;
    }
};

int main()
{
	vector<int> preorder{1,2,4,5,3,6};
	vector<int> inorder{4,2,5,1,3,6};

	Solution so;
	auto root = so.buildTree(preorder, inorder);

	print_preorder(root); cout << endl;;
	print_inorder(root); cout << endl;;

	rm_tree(root);

	return 0;
}

//   1
//  2 3
// 4 5 6
// 
// 1 2 4 5 3 6
// 4 2 5 1 3 6
