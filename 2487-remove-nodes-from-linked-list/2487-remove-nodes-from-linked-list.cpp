class Solution {
public:
    void recursiveReverse(ListNode* &head, ListNode* current, ListNode* prev) {
        if (current == nullptr) {
            head = prev;
            return;
        }
        
        ListNode* forward = current->next;
        recursiveReverse(head, forward, current);
        current->next = prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* reversedHead = nullptr;  // Used for reversed list
        ListNode* current = head;
        ListNode* prev = nullptr;
        recursiveReverse(reversedHead, current, prev);
       
        int maxx = reversedHead->val;
        current = reversedHead;
        prev = nullptr;
        
        while (current != nullptr && current->next != nullptr) {
            if (current->next->val < maxx) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;  // Remove the node properly
            } else {
                maxx = max(maxx, current->next->val);
                current = current->next;
            }
        }
        
        // Re-reverse the 
        current = reversedHead;
        prev = nullptr;
        recursiveReverse(head, current, prev);
        
        return head;
    }
};
