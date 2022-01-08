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
    ListNode* temp;
    //vector<int> v;
public:
    Solution(ListNode* head) {
        temp = head;  
        // while(temp != NULL){
        //     v.push_back(temp->val);
        //     temp = temp->next;
        // }
    }
    
    int getRandom() {
        // int size = v.size();
        // return v[rand()%size];
        int index = 1;
        int ans = 0;
        
        ListNode* cur = temp;
        while(cur){
            if(rand()%index == 0){
                ans = cur->val;
            }
            cur = cur->next;
            index++;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */