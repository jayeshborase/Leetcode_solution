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
    ListNode* merge(ListNode* l2, ListNode* l1){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val > l2->val)
            swap(l1,l2);
        ListNode* res = l1;
        while(l1 != NULL && l2 != NULL){
            ListNode* tem = NULL;
            while(l1 != NULL && l1->val <= l2->val){
                tem = l1;
                l1 = l1->next;
            }
            tem->next = l2;
            swap(l1,l2);
        }
        return res;
    } 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        else if(lists.size() == 1)
            return lists[0];
        ListNode* l1 = lists[0];
        for(int i = 1; i < lists.size(); i++){
            ListNode* l2 = lists[i];
            l1 = merge(l2, l1);
        }
        return l1;
    }
};