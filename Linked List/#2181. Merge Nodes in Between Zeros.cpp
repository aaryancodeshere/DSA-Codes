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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr= head->next;
        ListNode* newnode=new ListNode(0);
        ListNode* ans=newnode;
        int sum=0;
        while(curr){
            if(curr->val==0){
                ListNode* temp= new ListNode(sum);
                newnode->next=temp;
                newnode=temp;
                sum=0;
            }
            else{
                sum+=curr->val;
            }

                curr=curr->next;
            
        }
        return ans->next;

    }
};