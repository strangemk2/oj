#include <initializer_list>

using namespace std;

template<typename NODE, typename VALUE>
NODE *make_linked_list(initializer_list<VALUE> values)
{
	NODE *head = nullptr;
	NODE *current = nullptr;
	for (auto it : values)
	{
		if (head == nullptr)
		{
			head = new NODE(it);
			current = head;
		}
		else
		{
			current->next = new NODE(it);
			current = current->next;
		}
	}
	return head;
}

template<typename NODE>
void print_linked_list(const NODE *head)
{
	while (head)
	{
		cout << head->val << ", ";
		head = head->next;
	}
	cout << endl;
}

