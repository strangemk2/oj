#include "leetcode.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr)
		{
			return nullptr;
		}

		auto workA = headA;
		auto workB = headB;

		while (workA != nullptr && workB != nullptr)
		{
			if (workA == workB)
			{
				return workA;
			}
			workA = workA->next;
			workB = workB->next;
			if (workA == nullptr && workB != nullptr)
			{
				workA = headB;
			}
			if (workB == nullptr && workA != nullptr)
			{
				workB = headA;
			}
		}

		return nullptr;
	}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		auto length_a = list_length(headA);
		auto length_b = list_length(headB);
        
		if (length_a == 0 || length_b == 0)
		{
			return nullptr;
		}

		if (length_a > length_b)
		{
			for (int i = 0; i < (length_a - length_b); i++)
			{
				headA = headA->next;
			}
		}
		if (length_b > length_a)
		{
			for (int i = 0; i < (length_b - length_a); i++)
			{
				headB = headB->next;
			}
		}

		while (headA != nullptr && headB != nullptr)
		{
			if (headA == headB)
			{
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return nullptr;
    }

	int list_length(ListNode *head)
	{
		int ret = 0;
		while (head != nullptr)
		{
			head = head->next;
			ret++;
		}
		cout << ret << endl;
		return ret;
	}
};

int main()
{
	ListNode *headA = make_linked_list<ListNode, int>({1});
	ListNode *headB = nullptr;

	Solution so;
	cout << so.getIntersectionNode(headA, headB) << endl;;

	return 0;
}
