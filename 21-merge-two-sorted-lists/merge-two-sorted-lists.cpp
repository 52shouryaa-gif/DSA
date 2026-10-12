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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* List1 = list1;
        ListNode* List2 = list2;
      ListNode* dummy = new ListNode (0);
      ListNode* temp = dummy;
      while(List1 && List2){
        if(List1 -> val < List2 -> val){
            temp -> next = List1;
            temp = List1;
            List1 = List1 -> next;
        }
      
        else {
             temp -> next = List2;
            temp = List2;
            List2 = List2 -> next;
        }
      }
      if(List1) temp -> next = List1;
      else temp-> next = List2;
    return dummy -> next;
    }
};