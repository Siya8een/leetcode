class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head; // No rotation needed
        }

        ListNode* curr = head;
        int count = 1; // Count the number of nodes in the list

        // Traverse to the end of the list and count the nodes
        while (curr->next != NULL) {
            curr = curr->next;
            count++;
        }

        // Connect the last node to the head to form a circular list
        curr->next = head;

        // Calculate the effective rotation steps (k mod count)
        k = k % count;

        // Find the new tail node position (count - k)
        for (int i = 0; i < count - k; i++) {
            curr = curr->next;
        }

        // The new head is the next node after the new tail
        head = curr->next;

        // Set the next of the new tail to NULL to break the circular list
        curr->next = NULL;

        return head;
    }
};
