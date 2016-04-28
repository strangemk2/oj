#include "leetcode.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{}
};

int main()
{
	auto root = make_binary_tree<TreeNode, int>({1,2,3,4,5,6,7,'#',9,10, 11, 12});
	print_binary_tree_preorder<TreeNode, int>(root);
	cout << endl;
	print_binary_tree_inorder<TreeNode, int>(root);
	cout << endl;
	print_binary_tree_postorder<TreeNode, int>(root);
	cout << endl;

	return 0;
}
