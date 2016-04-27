#include <iostream>
#include <memory>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		auto h = head;
		for (int i = 0; i < m - 2 ; ++i)
		{
			h = h->next;
		}
		auto ptr_before_m = h;
		auto ptr_m = h->next;
		if (m <= 1)
		{
			ptr_before_m = nullptr;
			ptr_m = head;
		}
		ListNode *ptr_after_n = nullptr;
		auto ptr_reversed = reverse(ptr_m, n - m + 1, ptr_after_n);
		if (ptr_before_m != nullptr)
		{
			ptr_before_m->next = ptr_reversed;
		}
		else
		{
			head = ptr_reversed;
		}

		if (ptr_after_n != nullptr)
		{
			ptr_m->next = ptr_after_n;
		}

		return head;
    }
	ListNode *reverse(ListNode *head, int length, ListNode *&last)
	{
		ListNode *result = nullptr;
		int i = 0;
		while (head && i < length)
		{
			auto t = head->next;
			head->next = result;
			result = head;
			head = t;

			++i;
		}
		last = head;
		return result;
	}
};

ListNode *init_list()
{
	auto head = new ListNode(1);
	auto h = head;

	for (int i = 2; i <= 10; ++i)
	{
		auto node = new ListNode(i);
		h->next = node;
		h = node;
	}
	h->next = NULL;

	return head;
}

void print_list(ListNode *head)
{
	while (head)
	{
		cout << head->val << ", ";
		head = head->next;
	}
	cout << endl;
}

void del_list(ListNode *head)
{
	while (head)
	{
		auto tmp = head->next;
		delete(head);
		head = tmp;
	}
}

int main()
{
	auto list = init_list();
	print_list(list);

	Solution so;
	auto h = so.reverseBetween(list, 1, 8);

	print_list(h);
	del_list(h);

	return 0;
}
