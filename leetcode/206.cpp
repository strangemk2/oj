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
    ListNode* reverseList(ListNode* head)
	{
		ListNode *new_head = nullptr;

		while (head != nullptr)
		{
			ListNode *next = nullptr;
			if (new_head == nullptr)
			{
				new_head = head;
				next = head->next;
				head->next = nullptr;
			}
			else
			{
				next = head->next;
				ListNode *local_head = new_head;
				new_head = head;
				new_head->next = local_head;
			}

			head = next;
		}

		return new_head;
    }
};

int main()
{
	auto head = make_linked_list<ListNode, int>({1,2,3,4,5});
	print_linked_list(head);
	Solution so;
	head = so.reverseList(head);
	print_linked_list(head);

	return 0;
}
