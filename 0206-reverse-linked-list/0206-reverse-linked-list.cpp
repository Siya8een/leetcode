class Solution {
public:
    void recursiveReverse(ListNode* &head, ListNode* current, ListNode* prev) {
        if (current == nullptr ) {
            head = prev;
            return;
        }
        
        ListNode* forward = current->next;
        recursiveReverse(head, forward, current);
        current->next = prev;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* current = head;
        ListNode* prev = nullptr;
        recursiveReverse(head, current, prev);
        return head;
    }
};
