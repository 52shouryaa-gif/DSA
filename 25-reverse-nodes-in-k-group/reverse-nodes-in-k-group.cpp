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
    ListNode* rr(ListNode* temp, int k) {
        k-=1;
        while (temp && k > 0) {
k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rev(ListNode* temp){
        ListNode* prev = NULL;
        while(temp){
            ListNode* nextNode = temp->next;
            temp -> next = prev;
            prev = temp;
            temp =nextNode;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp) {
            ListNode* kthnode = rr(temp, k);
            if (!kthnode) {
                if (prev){
                    prev->next = temp;
                }
                break;
            }
            ListNode* nextnode = kthnode->next;
            kthnode->next = nullptr;
            rev(temp);
            if(temp == head){
                head = kthnode;
            }
            else prev -> next = kthnode;
            prev = temp;
            temp = nextnode;
            
        }
        return head;
    }
};