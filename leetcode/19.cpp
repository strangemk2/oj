/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto slow = head;
        auto fast = head;
        
        int i;
        for (i = 0; i < n && fast != nullptr; ++i)
        {
            fast = fast->next;
        }
        if (i == n && fast == nullptr)
        {
            return head->next;
        }
        
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        auto destination = slow->next;
        if (destination->next != nullptr)
        {
            slow->next = destination->next;
        }
        else
        {
            slow->next = nullptr;
        }
        return head;
    }
};
