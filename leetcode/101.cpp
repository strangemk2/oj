#include "leetcode.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool symmetric_compare(TreeNode *roota, TreeNode *rootb)
	{
		if (roota == nullptr && rootb == nullptr)
		{
			return true;
		}

		if ((roota == nullptr && rootb != nullptr) ||
				(roota != nullptr && rootb == nullptr))
		{
			return false;
		}

		if (roota->val != rootb->val)
		{
			return false;
		}

		return symmetric_compare(roota->left, rootb->right) &&
			symmetric_compare(roota->right, rootb->left);
	}

    bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}

		return symmetric_compare(root->left, root->right);
    }

};

int main()
{
	auto root = make_binary_tree<TreeNode, int>({1,2,2,'#',3,'#',3});
	Solution so;
	cout << so.isSymmetric(root) << endl;

	return 0;
}
