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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return head;
        }
        
        auto current = head;
        head = head->next;
        ListNode *prev = nullptr;
        while (true)
        {
            auto left = current;
            if (current == nullptr)
            {
                return head;
            }
            auto right = current->next;
            if (right == nullptr)
            {
                return head;
            }
            current = right->next;
            
            left->next = right->next;
            right->next = left;
            
            if (prev != nullptr) prev->next = right;
            prev = left;
        }
        return head;
    }
};
