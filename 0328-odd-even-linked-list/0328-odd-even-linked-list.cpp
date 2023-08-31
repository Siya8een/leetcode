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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // Empty list or list with only one node
        }
        
        ListNode* oddHead = nullptr;
        ListNode* oddTail = nullptr;
        ListNode* evenHead = nullptr;
        ListNode* evenTail = nullptr;
        
        ListNode* current = head;
        int index = 1;
        
        while (current != nullptr) {
            if (index % 2 == 1) {
                // Odd node
                if (oddHead == nullptr) {
                    oddHead = oddTail = current;
                } else {
                    oddTail->next = current;
                    oddTail = oddTail->next;
                }
            } else {
                // Even node
                if (evenHead == nullptr) {
                    evenHead = evenTail = current;
                } else {
                    evenTail->next = current;
                    evenTail = evenTail->next;
                }
            }
            
            current = current->next;
            index++;
        }
        
        if (oddHead == nullptr) {
            // No odd nodes, return the even list as is
            return evenHead;
        }
        
        oddTail->next = evenHead;
        
        if (evenTail != nullptr) {
            evenTail->next = nullptr;
        }
        
        return oddHead;
    }
};
