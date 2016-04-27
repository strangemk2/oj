/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class mylist
{
private:
    ListNode *head;
    ListNode *tail = nullptr;

public:
    mylist(ListNode *node):head(node)
    {}
    
    ListNode *append_pair(ListNode *node_pair)
    {
        auto left = node_pair;
        auto right = node_pair->next;
        if (head == nullptr)
        {
            head = left;
        }
        else
        {
            tail->next = left;
        }
        tail = right;
    }
    ListNode *shift_pair()
    {
        ListNode *t = nullptr;
        if (head != nullptr)
        {
            if (head->next != nullptr)
            {
                auto new_head = head->next->next;
                head->next->next = nullptr;
                t = head;
                head = new_head;
            }
            else
            {
                t = head;
                head = nullptr;
            }
        }
        return t;
    }
    ListNode *get_head()
    {
        return head;
    }
};
class Solution {
public:
    ListNode *swap_node(ListNode *node_pair)
    {
        auto left = node_pair;
        auto right = node_pair->next;
        if (right == nullptr)
        {
            return left;
        }
        else
        {
            right->next = left;
            left->next = nullptr;
            return right;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return head;
        }
        
        mylist swapped_list(nullptr);
        mylist original_list(head);
        
        while (true)
        {
            auto node_pair = original_list.shift_pair();
            if (node_pair == nullptr)
            {
                break;
            }
            cout << node_pair->val << endl;
            node_pair = swap_node(node_pair);
            swapped_list.append_pair(node_pair);
        }
        return swapped_list.get_head();
    }
};
