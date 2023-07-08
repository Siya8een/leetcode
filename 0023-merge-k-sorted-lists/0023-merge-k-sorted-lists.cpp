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
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         
        ListNode *dummy=new ListNode(-1);
        ListNode *head=dummy;
        while(list1 && list2){
            if(list1->val < list2->val){
                head->next=list1;
                head=head->next;
                list1=list1->next;
            }
                else {
                head->next=list2;
                head=head->next;
                list2=list2->next;
            }
        }

        if(list1){
                head->next=list1;
                head=head->next;
        }

         if(list2){
            head->next=list2;
                head=head->next;
        }

        return dummy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
             if(n==0) return NULL;
             if(n==1) return lists[0];
            ListNode *node =mergeTwoLists(lists[0],lists[1]);
              if(n==2) return node;
       for(int i=2;i<lists.size();i++){
             node=mergeTwoLists(node,lists[i]);
       }
       return node;
    }
};