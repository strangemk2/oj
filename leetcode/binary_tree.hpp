#include <initializer_list>
#include <functional>
#include <queue>

using namespace std;

template<typename IT_TYPE>
auto double_read(IT_TYPE begin, IT_TYPE end) -> function<bool (IT_TYPE &, IT_TYPE &)>
{
	IT_TYPE l_begin = begin;
	IT_TYPE l_end = end;
	return [=](IT_TYPE &left, IT_TYPE &right) mutable -> bool
	{
		left = l_begin;
		if (l_begin != l_end) l_begin++;

		right = l_begin;
		if (l_begin != l_end) l_begin++;

		return l_begin != l_end ? true : false;
	};
}

template<typename NODE, typename VALUE>
NODE *make_binary_tree(initializer_list<VALUE> values)
{
	NODE *head = nullptr;

	if (values.size() == 0)
	{
		return head;
	}

	auto root_it = values.begin();
	head = new NODE(*root_it);

	queue<NODE *> node_queue;
	node_queue.push(head);

	auto initializer_list_reader = double_read(values.begin()+1, values.end());
	while (true)
	{
		typename initializer_list<VALUE>::iterator left_it;
		typename initializer_list<VALUE>::iterator right_it;

		if (node_queue.size() == 0)
		{
			break;
		}

		auto current = node_queue.front();
		node_queue.pop();

		initializer_list_reader(left_it, right_it);
		if (left_it == values.end())
		{
			break;
		}
		if (*left_it != '#')
		{
			current->left = new NODE(*left_it);
			node_queue.push(current->left);
		}

		if (right_it == values.end())
		{
			break;
		}
		if (*right_it != '#')
		{
			current->right = new NODE(*right_it);
			node_queue.push(current->right);
		}
	}

	return head;
}

// pre order
// in order
// post order

template<typename NODE, typename FUNC>
void traversal_binary_tree_preorder(const NODE *head, FUNC f)
{
	if (head == nullptr)
		return;

	f(head->val);
	traversal_binary_tree_preorder(head->left, f);
	traversal_binary_tree_preorder(head->right, f);
}
template<typename NODE, typename FUNC>
void traversal_binary_tree_inorder(const NODE *head, FUNC f)
{
	if (head == nullptr)
		return;

	traversal_binary_tree_inorder(head->left, f);
	f(head->val);
	traversal_binary_tree_inorder(head->right, f);
}
template<typename NODE, typename FUNC>
void traversal_binary_tree_postorder(const NODE *head, FUNC f)
{
	if (head == nullptr)
		return;

	traversal_binary_tree_postorder(head->left, f);
	traversal_binary_tree_postorder(head->right, f);
	f(head->val);
}

template<typename NODE, typename VALUE>
void print_binary_tree_preorder(const NODE *head)
{
	traversal_binary_tree_preorder(head, [](VALUE v) {cout << v << ", ";});
}
template<typename NODE, typename VALUE>
void print_binary_tree_inorder(const NODE *head)
{
	traversal_binary_tree_inorder(head, [](VALUE v) {cout << v << ", ";});
}
template<typename NODE, typename VALUE>
void print_binary_tree_postorder(const NODE *head)
{
	traversal_binary_tree_postorder(head, [](VALUE v) {cout << v << ", ";});
}
