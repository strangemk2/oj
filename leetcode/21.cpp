#include <iostream>

using namespace std;
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
    function<ListNode *()> node_iterator(ListNode *&node)
    {
        return [node]() mutable
        {
            if (node != nullptr)
            {
                auto current = node;
                node = node->next;
                return current;
            }
            else
            {
                return node;
            }
        };
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        auto it1 = node_iterator(l1);
        auto it2 = node_iterator(l2);
        
        ListNode *node1 = it1();
        ListNode *node2 = it2();
        ListNode *head = nullptr;
        ListNode *last = nullptr;
        while (node1 != nullptr || node2 != nullptr)
        {
            ListNode *insert_node = nullptr;
            if (node2 == nullptr || (node1 != nullptr && node1->val <= node2->val))
            {
                insert_node = node1;
                node1 = it1();
            }
            else
            {
                insert_node = node2;
                node2 = it2();
            }
            
            if (head == nullptr)
            {
                head = insert_node;
                last = head;
            }
            else
            {
                last->next = insert_node;
                last = insert_node;
            }
        }
        return head;
    }
};

int main()
{
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	Solution so;
	auto c = so.mergeTwoLists(a, b);
	while (c != nullptr)
	{
		cout << c->val << ",";
		c = c->next;
	}
	cout << endl;

	return 0;
}
