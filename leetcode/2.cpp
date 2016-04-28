#include "leetcode.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class reverse_number
{
private:
	ListNode *head = nullptr;
	ListNode *current = nullptr;

public:
	reverse_number(ListNode *h):head(h)
	{}

	ListNode *get_head()
	{
		return head;
	}

	void push_digit(int n)
	{
		if (head == nullptr)
		{
			head = new ListNode(n);
			current = head;
		}
		else
		{
			current->next = new ListNode(n);
			current = current->next;
		}
	}

	int top()
	{
		return head!=nullptr?head->val:0;
	}

	bool unshift()
	{
		if (head == nullptr)
		{
			return false;
		}
		else
		{
			head = head->next;
			return true;
		}
	}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int v1 = 0, v2 = 0;
		bool carridge = false;
		reverse_number n1(l1);
		reverse_number n2(l2);
		reverse_number ret(nullptr);
		while (true)
		{
			v1 = n1.top();
			v2 = n2.top();
			auto n1_available = n1.unshift();
			auto n2_available = n2.unshift();
			if (!n1_available && !n2_available && !carridge)
			{
				break;
			}

			auto v = v1 + v2 + (carridge?1:0);
			if (v >= 10)
			{
				v -= 10;
				carridge = true;
			}
			else
			{
				carridge = false;
			}

			ret.push_digit(v);
		}

		return ret.get_head();
    }
};

int main()
{
	auto l1 = make_linked_list<ListNode, int>({9,9});
	auto l2 = make_linked_list<ListNode, int>({5,6,2});

	Solution so;
	auto l3 = so.addTwoNumbers(l1, l2);
	print_linked_list(l3);

	return 0;
}
