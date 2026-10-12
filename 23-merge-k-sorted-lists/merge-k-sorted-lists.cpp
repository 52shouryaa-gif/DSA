class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                res->next = l1;
                l1 = l1->next;
            } else {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        
        if (l1 != nullptr) res->next = l1;
        else res->next = l2;
        
        return dummyNode->next;
    }

    ListNode* helper(vector<ListNode*>& lists, int i) {
        if (i == lists.size() - 1) return lists[i];
        if (i >= lists.size()) return nullptr;
        
        ListNode* mergedHead = helper(lists, i + 1);
        
        return mergeTwoLists(lists[i], mergedHead);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return helper(lists, 0);
    }
};