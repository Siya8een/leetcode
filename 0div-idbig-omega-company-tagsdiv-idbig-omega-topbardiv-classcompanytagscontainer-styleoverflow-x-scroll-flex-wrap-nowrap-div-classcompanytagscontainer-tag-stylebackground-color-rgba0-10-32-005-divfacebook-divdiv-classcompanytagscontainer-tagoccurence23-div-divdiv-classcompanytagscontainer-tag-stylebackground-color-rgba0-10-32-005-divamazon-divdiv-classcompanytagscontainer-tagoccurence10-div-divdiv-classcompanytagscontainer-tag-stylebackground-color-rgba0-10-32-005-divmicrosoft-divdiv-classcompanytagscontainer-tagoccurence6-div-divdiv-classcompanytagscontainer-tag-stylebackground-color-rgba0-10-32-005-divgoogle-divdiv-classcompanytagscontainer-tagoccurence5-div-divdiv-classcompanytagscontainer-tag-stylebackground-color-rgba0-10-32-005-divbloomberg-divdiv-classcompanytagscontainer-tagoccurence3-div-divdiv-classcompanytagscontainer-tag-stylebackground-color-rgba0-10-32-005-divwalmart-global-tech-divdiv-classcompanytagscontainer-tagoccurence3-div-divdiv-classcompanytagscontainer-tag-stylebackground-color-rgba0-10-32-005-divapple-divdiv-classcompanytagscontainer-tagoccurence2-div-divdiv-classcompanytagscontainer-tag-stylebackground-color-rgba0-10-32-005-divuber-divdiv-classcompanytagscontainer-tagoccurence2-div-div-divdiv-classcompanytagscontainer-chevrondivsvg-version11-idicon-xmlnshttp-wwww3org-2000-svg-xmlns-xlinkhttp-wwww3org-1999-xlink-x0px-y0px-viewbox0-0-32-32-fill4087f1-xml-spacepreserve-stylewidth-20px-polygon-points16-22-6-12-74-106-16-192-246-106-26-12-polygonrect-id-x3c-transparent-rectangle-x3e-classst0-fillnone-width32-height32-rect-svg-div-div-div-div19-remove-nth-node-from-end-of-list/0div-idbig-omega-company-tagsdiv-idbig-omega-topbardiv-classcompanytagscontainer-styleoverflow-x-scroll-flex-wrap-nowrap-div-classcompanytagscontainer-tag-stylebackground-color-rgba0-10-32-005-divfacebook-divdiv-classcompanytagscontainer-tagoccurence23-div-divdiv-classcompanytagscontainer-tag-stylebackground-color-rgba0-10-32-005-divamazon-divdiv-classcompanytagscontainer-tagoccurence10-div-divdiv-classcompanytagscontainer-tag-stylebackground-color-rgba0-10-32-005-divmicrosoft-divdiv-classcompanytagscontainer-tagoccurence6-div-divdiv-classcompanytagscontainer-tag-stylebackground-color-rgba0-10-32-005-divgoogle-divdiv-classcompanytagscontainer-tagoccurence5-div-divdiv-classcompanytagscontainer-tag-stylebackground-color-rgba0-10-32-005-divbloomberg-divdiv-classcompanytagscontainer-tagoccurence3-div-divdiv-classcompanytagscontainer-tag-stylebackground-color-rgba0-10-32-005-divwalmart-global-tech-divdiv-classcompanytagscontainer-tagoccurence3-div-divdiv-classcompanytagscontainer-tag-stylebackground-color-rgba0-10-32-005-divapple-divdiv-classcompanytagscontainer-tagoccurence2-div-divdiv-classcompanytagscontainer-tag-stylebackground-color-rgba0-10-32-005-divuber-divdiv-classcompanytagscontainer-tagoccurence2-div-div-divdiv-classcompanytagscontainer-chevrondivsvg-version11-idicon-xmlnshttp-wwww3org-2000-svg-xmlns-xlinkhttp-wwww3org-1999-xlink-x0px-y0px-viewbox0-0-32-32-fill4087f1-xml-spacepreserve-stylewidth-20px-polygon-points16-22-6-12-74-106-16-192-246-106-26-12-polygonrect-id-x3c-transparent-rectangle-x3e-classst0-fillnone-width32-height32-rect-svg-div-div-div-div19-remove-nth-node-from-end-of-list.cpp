/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr; // Empty list, nothing to remove
        }
        
        ListNode* dummy = new ListNode(0); // Create a dummy node to handle edge cases
        dummy->next = head;
        
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Move fast to the end, maintaining the gap
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Skip the nth node from the end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        
        delete toDelete; // Free the memory
        
        return dummy->next; // Return the modified head
    }
};
