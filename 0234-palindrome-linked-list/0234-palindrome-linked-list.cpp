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
    private:
     ListNode* findMid(ListNode* head){
             ListNode *slow=head;
   ListNode *fast=head;
    ListNode *temp=fast->next;
    while(fast->next!=NULL&& fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
   return slow;

     }
    ListNode* reverse(ListNode* temp){
         ListNode* prev = NULL;
        ListNode* curr = temp;
        ListNode* forward = NULL;
        
        while(curr!= NULL){
            forward = curr->next ;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;


    }
    


public:
    bool isPalindrome(ListNode* head) {
         if (head == NULL || head-> next == NULL){
             return true;
         }
          ListNode* middle= findMid(head);
          // reversing list after middle(after middle i have to reverse the list)
          ListNode* temp= middle -> next;
          middle-> next = reverse (temp);
          ListNode* Start1= head;
          ListNode* Start2= middle -> next;
          while (Start2 != NULL){
              if (Start1 -> val != Start2-> val ){
                  return false;
                  
              }
              Start1= Start1 -> next;
              Start2= Start2 -> next;

          }
          return true;


    }
};