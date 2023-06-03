class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        ListNode* forward = head;

        while (forward != nullptr && forward->next != nullptr) {
            curr = curr->next;
            forward = forward->next->next;
        }

        return curr;
    }
};
