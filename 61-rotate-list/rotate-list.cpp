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
    
    ListNode* re(ListNode* head, int t){
        ListNode* temp = head;
        t--;
        while(t-- && temp -> next ){
            temp = temp -> next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head) return head;
        ListNode* temp = head;
        int len = 1;
        while(temp -> next){
            len++;
            temp = temp -> next;
        }
        if(k%len == 0) return head;
        k = k%len;
        temp -> next = head;
        ListNode* t = re(head , len - k);
        head = t -> next;
        t -> next = nullptr;
        return head;
    }
};