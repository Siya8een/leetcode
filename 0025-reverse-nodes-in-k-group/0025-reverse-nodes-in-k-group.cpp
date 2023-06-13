
class Solution {
public:
   int lengthOfList(ListNode* head){
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            length++;
        }
        return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head,*next;
        int count = 0;
        while(temp){
            count++;
            if(count==k){
                break;
            }
            temp = temp->next;
        }
        if(count < k){
            return head;
        }
        next = reverseKGroup(temp->next,k);
        ListNode* curr = head,*prev = NULL,*store = NULL;
        for(int i = 0; i < k;i++){
            store = curr->next;
            curr->next = prev;
            prev = curr;
            curr = store;
        }
        head->next = next;
        return prev;
    }
};