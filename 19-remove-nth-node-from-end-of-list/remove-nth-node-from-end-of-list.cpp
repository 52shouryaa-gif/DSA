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
      ListNode* dummy = new ListNode(0 , head);
        ListNode* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        int k = cnt - n;
        ListNode* nt = dummy;
        while ( k--) {
            nt = nt->next;
        }
        ListNode* tt = nt -> next;
        nt -> next = nt -> next -> next;
        delete tt;
    
        return dummy -> next ;
    }
};