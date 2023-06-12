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
   

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* dummy1 = headA;
    ListNode* dummy2 = headB;
    int count1 = 0;
    int count2 = 0;

    while (dummy1 != NULL) {
        count1++;
        dummy1 = dummy1->next;
    }

    while (dummy2 != NULL) {
        count2++;
        dummy2 = dummy2->next;
    }

    int count = abs(count1 - count2);
    ListNode* dummy = headA;
    ListNode* otherDummy = headB;

    if (count1 > count2) {
        dummy = headA;
        otherDummy = headB;
    } else {
        dummy = headB;
        otherDummy = headA;
    }

    for (int i = 0; i < count; i++) {
        dummy = dummy->next;
    }

    while (dummy != NULL && otherDummy != NULL) {
        if (dummy == otherDummy) {
            return dummy;
        }
        dummy = dummy->next;
        otherDummy = otherDummy->next;
    }

    return NULL;
}
};
