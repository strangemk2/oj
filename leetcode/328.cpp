#include "leetcode.h"
#include <set>
#include <limits>
#include <cmath>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	bool is_odd(int n)
	{
		return n % 2;
	}

    ListNode* oddEvenList(ListNode* head)
	{
		ListNode *odd_list = nullptr;
		ListNode *even_list = nullptr;
		ListNode *odd_list_head = nullptr;
		ListNode *even_list_head = nullptr;

		ListNode *current = head;

		int count = 1;
		while (current != nullptr)
		{
			auto next = current->next;
			if (is_odd(count++))
			{
				if (odd_list_head == nullptr)
				{
					odd_list_head = current;
					odd_list = current;
				}
				else
				{
					odd_list->next = current;
					odd_list = odd_list->next;
				}
				odd_list->next = nullptr;
			}
			else
			{
				if (even_list_head == nullptr)
				{
					even_list_head = current;
					even_list = current;
				}
				else
				{
					even_list->next = current;
					even_list = even_list->next;
				}
				even_list->next = nullptr;
			}
			current = next;
		}
		if (odd_list == nullptr)
		{
			return even_list_head;
		}
		else
		{
			odd_list->next = even_list_head;
			return odd_list_head;
		}
    }
};

int main()
{
	auto head = make_linked_list<ListNode, int>({1,2,3,4,5});
	print_linked_list(head);
	Solution so;
	auto head2 = so.oddEvenList(head);
	print_linked_list(head2);

	return 0;
}
