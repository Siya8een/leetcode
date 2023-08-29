class Solution {
public:
    
    
    ListNode* reverseList(ListNode* head) {
        // Base case: If the list is empty or has only one node, no need to reverse
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* restReversed = reverseList(head->next); // Reverse the rest of the list

        // Adjust the pointers to reverse the current node
        head->next->next = head;
        head->next = nullptr;

        return restReversed; // Return the new head of the reversed list
    }
};

