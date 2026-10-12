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
   ListNode* sorti(ListNode* List1 , ListNode* List2){
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    ListNode* list1 = List1;
    ListNode* list2 = List2;
    while(list1 && list2){
        if(list1 -> val > list2 -> val){
           temp -> next = list2;
           temp = list2;
           list2 = list2 -> next;
        }
        else{
           temp -> next = list1;
           temp = list1;
           list1 = list1 -> next;
        }
    }
    if(list1) temp -> next = list1;
    if(list2) temp -> next = list2;
    return dummy -> next;
   }
    ListNode* merge(vector<ListNode*>& lists , int start , int end){
        if(start > end) return nullptr;
        if(start == end) return lists[start];

        int mid = start - (start - end)/2;
        ListNode* left = merge(lists , start , mid);
        ListNode* right = merge(lists , mid+1 , end);
        ListNode* srt = sorti(left , right);

        return srt;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return merge(lists , 0 , lists.size() - 1);
    }
};