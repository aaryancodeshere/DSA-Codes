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
        if(!head){
            return head;
        }
        ListNode* ans = head;
        while(head && head->next && head->next->next){
            int temp = head->val;
            head->val = head -> next->val;
            head->next->val = temp;

            head = head -> next -> next;
        }
        if(head->next){
            int temp = head->val;
            head->val = head -> next->val;
            head->next->val = temp;
        }
        return ans;
    }
};