#include "leetcode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
	int get_length(ListNode *head)
	{
		int length = 0;
		while (head != nullptr)
		{
			head = head->next;
			length++;
		}

		return length;
	}

    ListNode* rotateRight(ListNode* head, int k)
	{
		if (head == nullptr) return head;

		auto length = get_length(head);
		k %= length;
		if (k == 0) return head;

		ListNode *tail = head;
		for (int i = 0; i < length - k - 1; ++i)
		{
			tail = tail->next;
		}

		auto new_head = tail->next;
		tail->next = nullptr;

		auto new_tail = new_head;
		while (new_tail->next != nullptr)
		{
			new_tail = new_tail->next;
		}
		new_tail->next = head;

		return new_head;
    }
};

int main()
{
	auto head = make_linked_list<ListNode, int>({1,2,3,4,5});
	print_linked_list(head);
	Solution so;
	head = so.rotateRight(head, 4);
	print_linked_list(head);

	return 0;
}
