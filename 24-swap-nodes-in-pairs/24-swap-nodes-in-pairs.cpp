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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = head;
        ListNode* move = head;
        
        while(move != NULL && move->next != NULL){
            pre = move;
            move = move->next;
            swap(pre->val, move->val);
            move= move->next;
        }
        return head;
    }
};