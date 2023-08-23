class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // If the list is empty or has only one node, no need to reverse
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;

        while (curr != nullptr) {
            nextNode = curr->next; // Store the next node
            curr->next = prev;     // Reverse the link

            // Move pointers to the next iteration
            prev = curr;
            curr = nextNode;
        }

        head = prev; // Update the new head of the reversed list
        return head;
    }
};
