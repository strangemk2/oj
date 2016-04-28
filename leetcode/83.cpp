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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
	{
		if (head == nullptr) return nullptr;

		auto node = head;
		while (node->next != nullptr)
		{
			if (node->val == node->next->val)
			{
				node->next = node->next->next;
			}
			else
			{
				node = node->next;
			}
		}

		return head;
    }
};

int main()
{
	auto head = make_linked_list<ListNode, int>({1,1,2,3,3});
	print_linked_list(head);
	Solution so;
	auto head2 = so.deleteDuplicates(head);
	print_linked_list(head2);
}
